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
        self.tokens: list[Token] = list(tokens)
        self.cur_token_idx: int = 0 # This is just a suggestion!

    def next_token(self) -> Token:
        if self.cur_token_idx < len(self.tokens):
            return self.tokens[self.cur_token_idx]
        else:
            return Token("", TokenType.EOF)
        
    def consume(self) -> None:
        if self.cur_token_idx < len(self.tokens):
            self.cur_token_idx += 1

    def match(self, token) -> None:
        next_token: Token = self.next_token()
        if next_token.kind == token:
            self.consume()
        else:
            raise Exception(f"Expected {token}, but got {next_token.kind}")

    def main(self) -> Expression:
        tree: Expression = self.E()
        self.match(TokenType.NLN)
        return tree

    def E(self) -> Expression:
        if self.next_token().kind == TokenType.NOT:
            self.consume()
            tree: Expression = self.E() # Check if this is correct
            tree = Not(tree)
            return tree
        else:
            tree: Expression = self.T()
            return tree
    
    def T(self) -> Expression:
        tree: Expression = self.F()
        while self.next_token().kind in (TokenType.LEQ, TokenType.LTH, TokenType.EQL):
            op: Token = self.next_token()
            self.consume()
            tree_right: Expression = self.F()

            if op.kind == TokenType.LEQ:
                tree = Leq(tree, tree_right)
            elif op.kind == TokenType.LTH:
                tree = Lth(tree, tree_right)
            elif op.kind == TokenType.EQL:
                tree = Eql(tree, tree_right)
        return tree
    
    def F(self) -> Expression:
        tree: Expression = self.P()
        while self.next_token().kind in (TokenType.ADD, TokenType.SUB):
            op: Token = self.next_token()
            self.consume()
            tree_right: Expression = self.P()

            if op.kind == TokenType.ADD:
                tree = Add(tree, tree_right)
            elif op.kind == TokenType.SUB:
                tree = Sub(tree, tree_right)
        return tree

    def P(self) -> Expression:
        tree: Expression = self.Q()
        while self.next_token().kind in (TokenType.MUL, TokenType.DIV):
            op: Token = self.next_token()
            self.consume()
            tree_right: Expression = self.Q()

            if op.kind == TokenType.MUL:
                tree = Mul(tree, tree_right)
            elif op.kind == TokenType.DIV:
                tree = Div(tree, tree_right)
        return tree

    def Q(self) -> Expression:
        tree: Expression
        if self.next_token().kind == TokenType.NUM:
            tree = Num(int(self.next_token().text))
            self.consume()
            return tree
        elif self.next_token().kind == TokenType.LPR:
            self.consume()
            tree = self.E()
            self.match(TokenType.RPR)
            return tree
        elif self.next_token().kind == TokenType.NEG:
            self.consume()
            tree = self.P()
            return Neg(tree)
        else:
            raise Exception(f"Unexpected token {self.next_token().text}")

    def parse(self):
        """
        Returns the expression associated with the stream of tokens.

        Examples:
        >>> parser = Parser([Token('123', TokenType.NUM)])
        >>> exp = parser.parse()
        >>> exp.eval()
        123

        >>> parser = Parser([Token('True', TokenType.TRU)])
        >>> exp = parser.parse()
        >>> exp.eval()
        True

        >>> parser = Parser([Token('False', TokenType.FLS)])
        >>> exp = parser.parse()
        >>> exp.eval()
        False

        >>> tk0 = Token('~', TokenType.NEG)
        >>> tk1 = Token('123', TokenType.NUM)
        >>> parser = Parser([tk0, tk1])
        >>> exp = parser.parse()
        >>> exp.eval()
        -123

        >>> tk0 = Token('3', TokenType.NUM)
        >>> tk1 = Token('*', TokenType.MUL)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
        12

        >>> tk0 = Token('3', TokenType.NUM)
        >>> tk1 = Token('*', TokenType.MUL)
        >>> tk2 = Token('~', TokenType.NEG)
        >>> tk3 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2, tk3])
        >>> exp = parser.parse()
        >>> exp.eval()
        -12

        >>> tk0 = Token('30', TokenType.NUM)
        >>> tk1 = Token('/', TokenType.DIV)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
        7

        >>> tk0 = Token('3', TokenType.NUM)
        >>> tk1 = Token('+', TokenType.ADD)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
        7

        >>> tk0 = Token('30', TokenType.NUM)
        >>> tk1 = Token('-', TokenType.SUB)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
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
        >>> exp.eval()
        14

        >>> tk0 = Token('4', TokenType.NUM)
        >>> tk1 = Token('==', TokenType.EQL)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
        True

        >>> tk0 = Token('4', TokenType.NUM)
        >>> tk1 = Token('<=', TokenType.LEQ)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
        True

        >>> tk0 = Token('4', TokenType.NUM)
        >>> tk1 = Token('<', TokenType.LTH)
        >>> tk2 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2])
        >>> exp = parser.parse()
        >>> exp.eval()
        False

        >>> tk0 = Token('not', TokenType.NOT)
        >>> tk1 = Token('4', TokenType.NUM)
        >>> tk2 = Token('<', TokenType.LTH)
        >>> tk3 = Token('4', TokenType.NUM)
        >>> parser = Parser([tk0, tk1, tk2, tk3])
        >>> exp = parser.parse()
        >>> exp.eval()
        True
        """

        return self.main()