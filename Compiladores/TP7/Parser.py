import sys

from Expression import *
from Lexer import Token, TokenType

"""
This file implements the parser of arithmetic expressions.

References:
    see https://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
"""

class Parser:
    def __init__(self, tokens):
        """
        Initializes the parser. The parser keeps track of the list of tokens
        and the current token. For instance:
        """
        self.tokens = list(tokens)
        self.cur_token_idx = 0 # This is just a suggestion!

    def next_token(self) -> Token:
        if self.cur_token_idx < len(self.tokens):
            return self.tokens[self.cur_token_idx]
        else:
            return Token("", TokenType.EOF)
        
    def consume(self) -> None:
        if self.cur_token_idx < len(self.tokens):
            self.cur_token_idx += 1

    def consume_newlines(self) -> None:
        while self.next_token().kind == TokenType.NLN and self.cur_token_idx < len(self.tokens):
            self.consume()

    def match(self, token) -> None:
        next_token: Token = self.next_token()
        if next_token.kind == token:
            self.consume()
            return True
        return False

    def main(self) -> Expression:
        if self.next_token().kind == TokenType.IFX:
            return self.if_then_else()
        return self.or_expression()
    
    def if_then_else(self) -> Expression:
        if not self.match(TokenType.IFX):
            sys.exit("Parse error")
        
        condition: Expression = self.main()
        self.consume_newlines()

        if not self.match(TokenType.THN):
            sys.exit("Parse error")

        then_branch: Expression = self.main()
        self.consume_newlines()
        
        if not self.match(TokenType.ELS):
            sys.exit("Parse error")

        else_branch: Expression = self.main()
        self.consume_newlines()

        return IfThenElse(condition, then_branch, else_branch)
    
    def or_expression(self) -> Expression:
        left = self.and_expression()

        while self.next_token().kind == TokenType.ORX:
            self.consume()
            right = self.and_expression()
            left = Or(left, right)

        return left
    
    def and_expression(self) -> Expression:
        left = self.eql_expression()

        while self.next_token().kind == TokenType.AND:
            self.consume()
            right = self.eql_expression()
            left = And(left, right)

        return left
    
    def eql_expression(self) -> Expression:
        left = self.comparison_expression()

        if self.match(TokenType.EQL):
            right = self.comparison_expression()
            return Eql(left, right)

        return left
    
    def comparison_expression(self) -> Expression:
        left = self.arithmetic_expression()

        while self.next_token().kind in (TokenType.LTH, TokenType.LEQ):
            if self.match(TokenType.LTH):
                right = self.arithmetic_expression()
                left = Lth(left, right)
            elif self.match(TokenType.LEQ):
                right = self.arithmetic_expression()
                left = Leq(left, right)

        return left

    def arithmetic_expression(self) -> Expression:
        left = self.term()

        while self.next_token().kind in (TokenType.ADD, TokenType.SUB):
            if self.match(TokenType.ADD):
                right = self.term()
                left = Add(left, right)
            elif self.match(TokenType.SUB):
                right = self.term()
                left = Sub(left, right)

        return left
    
    def term(self) -> Expression:
        left = self.factor()

        while self.next_token().kind in (TokenType.MUL, TokenType.DIV):
            if self.match(TokenType.MUL):
                right = self.factor()
                left = Mul(left, right)
            elif self.match(TokenType.DIV):
                right = self.factor()
                left = Div(left, right)

        return left
    
    def factor(self) -> Expression:
        if self.match(TokenType.NOT):
            return Not(self.factor())
        elif self.match(TokenType.NEG):
            return Neg(self.factor())
        elif self.match(TokenType.LPR):
            expr = self.main()
            if not self.match(TokenType.RPR):
                sys.exit("Parse error")
            return expr
        elif self.next_token().kind == TokenType.NUM:
            num_token = self.next_token()
            self.consume()
            return Num(int(num_token.text))
        elif self.match(TokenType.TRU):
            return Bln(True)
        elif self.match(TokenType.FLS):
            return Bln(False)
        elif self.next_token().kind == TokenType.VAR:
            var_name = self.next_token().text
            self.consume()
            return Var(var_name)
        elif self.match(TokenType.LET):
            return self.let_expression()
        elif self.match(TokenType.NLN):
            return self.factor()
        else:
            sys.exit("Parse error")

    def let_expression(self) -> Expression:
        self.consume_newlines()

        var = None
        if self.next_token().kind == TokenType.VAR:
            var = self.next_token().text
            self.consume()
        else:
            sys.exit("Parse error")

        if not self.match(TokenType.ASN):
            sys.exit("Parse error")

        value = self.main()
        self.consume_newlines()

        if not self.match(TokenType.INX):
            sys.exit("Parse error")

        self.consume_newlines()
        body = self.main()
        self.consume_newlines()

        if not self.match(TokenType.END):
            sys.exit("Parse error")

        return Let(var, value, body)

    def parse(self):
        """
        Returns the expression associated with the stream of tokens.

        Examples:
        >>> parser = Parser([Token('123', TokenType.NUM)])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        123

        >>> parser = Parser([Token('True', TokenType.TRU)])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        True

        >>> parser = Parser([Token('False', TokenType.FLS)])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        False

        >>> tk0 = Token('~', TokenType.NEG)
        >>> tk1 = Token('123', TokenType.NUM)
        >>> parser = Parser([tk0, tk1])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        -123

        >>> tk0 = Token('3', TokenType.NUM)
        >>> tk1 = Token('*', TokenType.MUL)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        12

        >>> tk0 = Token('3', TokenType.NUM)
        >>> tk1 = Token('*', TokenType.MUL)
        >>> tk2 = Token('~', TokenType.NEG)
        >>> tk3 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2, tk3])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        -12

        >>> tk0 = Token('30', TokenType.NUM)
        >>> tk1 = Token('/', TokenType.DIV)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        7

        >>> tk0 = Token('3', TokenType.NUM)
        >>> tk1 = Token('+', TokenType.ADD)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        7

        >>> tk0 = Token('30', TokenType.NUM)
        >>> tk1 = Token('-', TokenType.SUB)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        26

        >>> tk0 = Token('2', TokenType.NUM)
        >>> tk1 = Token('*', TokenType.MUL)
        >>> tk2 = Token('(', TokenType.LPR)
        >>> tk3 = Token('3', TokenType.NUM)
        >>> tk4 = Token('+', TokenType.ADD)
        >>> tk5 = Token('4', TokenType.NUM)
        >>> tk6 = Token(')', TokenType.RPR)
        >>> parser = Parser([tk0, tk1, tk2, tk3, tk4, tk5, tk6])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        14

        >>> tk0 = Token('4', TokenType.NUM)
        >>> tk1 = Token('==', TokenType.EQL)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        True

        >>> tk0 = Token('4', TokenType.NUM)
        >>> tk1 = Token('<=', TokenType.LEQ)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        True

        >>> tk0 = Token('4', TokenType.NUM)
        >>> tk1 = Token('<', TokenType.LTH)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        False

        >>> tk0 = Token('not', TokenType.NOT)
        >>> tk1 = Token('4', TokenType.NUM)
        >>> tk2 = Token('<', TokenType.LTH)
        >>> tk3 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2, tk3])
        >>> exp = parser.parse()
        >>> exp.eval(None)
        True

        >>> tk0 = Token('let', TokenType.LET)
        >>> tk1 = Token('v', TokenType.VAR)
        >>> tk2 = Token('<-', TokenType.ASN)
        >>> tk3 = Token('42', TokenType.NUM)
        >>> tk4 = Token('in', TokenType.INX)
        >>> tk5 = Token('v', TokenType.VAR)
        >>> tk6 = Token('end', TokenType.END)
        >>> parser = Parser([tk0, tk1, tk2, tk3, tk4, tk5, tk6])
        >>> exp = parser.parse()
        >>> exp.eval({})
        42

        >>> tk0 = Token('let', TokenType.LET)
        >>> tk1 = Token('v', TokenType.VAR)
        >>> tk2 = Token('<-', TokenType.ASN)
        >>> tk3 = Token('21', TokenType.NUM)
        >>> tk4 = Token('in', TokenType.INX)
        >>> tk5 = Token('v', TokenType.VAR)
        >>> tk6 = Token('+', TokenType.ADD)
        >>> tk7 = Token('v', TokenType.VAR)
        >>> tk8 = Token('end', TokenType.END)
        >>> parser = Parser([tk0, tk1, tk2, tk3, tk4, tk5, tk6, tk7, tk8])
        >>> exp = parser.parse()
        >>> exp.eval({})
        42
        """
        return self.main()