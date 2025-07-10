import sys
import enum
import re

class Token:
    """
    This class contains the definition of Tokens. A token has two fields: its
    text and its kind. The "kind" of a token is a constant that identifies it
    uniquely. See the TokenType to know the possible identifiers (if you want).
    You don't need to change this class.
    """
    def __init__(self, tokenText, tokenKind):
        # The token's actual text. Used for identifiers, strings, and numbers.
        self.text = tokenText
        # The TokenType that this token is classified as.
        self.kind = tokenKind


class TokenType(enum.Enum):
    """
    These are the possible tokens. You don't need to change this class at all.
    """
    EOF = -1  # End of file
    NLN = 0   # New line
    WSP = 1   # White Space
    COM = 2   # Comment
    NUM = 3   # Number (integers)
    STR = 4   # Strings
    TRU = 5   # The constant true
    FLS = 6   # The constant false
    EQL = 201
    ADD = 202
    SUB = 203
    MUL = 204
    DIV = 205
    LEQ = 206
    LTH = 207
    NEG = 208
    NOT = 209
    LPR = 210
    RPR = 211


class Lexer:
    
    def __init__(self, source):
        """
        The constructor of the lexer. It receives the string that shall be
        scanned.
        TODO: You will need to implement this method.
        """
        self.source = source
        self.index = 0
        pass

    def tokens(self):
        """
        This method is a token generator: it converts the string encapsulated
        into this object into a sequence of Tokens. Examples:

        >>> l = Lexer('1 * 2 - 3')
        >>> [tk.kind for tk in l.tokens()]
        [<TokenType.NUM: 3>, <TokenType.MUL: 204>, <TokenType.NUM: 3>, <TokenType.SUB: 203>, <TokenType.NUM: 3>]

        >>> l = Lexer('1 * 2 -- 3\\n')
        >>> [tk.kind for tk in l.tokens()]
        [<TokenType.NUM: 3>, <TokenType.MUL: 204>, <TokenType.NUM: 3>]
        """
        token = self.getToken()
        while token.kind != TokenType.EOF:
            if token.kind != TokenType.WSP and token.kind != TokenType.COM:
                yield token
            token = self.getToken()

    def getToken(self):
        """
        Return the next token.
        TODO: Implement this method!
        """

        if self.index >= len(self.source):
            return Token("", TokenType.EOF)
        
        tokenText = self.source[self.index]
        if tokenText == "\n":
            token = Token(tokenText, TokenType.NLN)
            self.index += 1
        elif tokenText == " ":
            token = Token(tokenText, TokenType.WSP)
            self.index += 1
        elif tokenText == "=":
            token = Token(tokenText, TokenType.EQL)
            self.index += 1
        elif tokenText == "+":
            token = Token(tokenText, TokenType.ADD)
            self.index += 1
        elif tokenText == "~":
            token = Token(tokenText, TokenType.NEG)
            self.index += 1
        elif tokenText == "-":
            # Check if the next is onother "-" to identify a comment
            if self.index + 1 < len(self.source) and self.source[self.index + 1] == "-":
                self.index += 1
                while self.index < len(self.source) and self.source[self.index] != "\n":
                    tokenText += self.source[self.index]
                    self.index += 1
                tokenText += self.source[self.index]
                self.index += 1
                token = Token(tokenText, TokenType.COM)

            # Check if the next character is a digit to identify negation
            elif self.index + 1 < len(self.source) and self.source[self.index + 1].isdigit():
                token = Token(tokenText, TokenType.NEG)
                self.index += 1

            # Check if the next character is a " " to identify subtraction
            else:
                token = Token(tokenText, TokenType.SUB)
                self.index += 1
        elif tokenText == "*":
            token = Token(tokenText, TokenType.MUL)
            self.index += 1
        elif tokenText == "/":
            token = Token(tokenText, TokenType.DIV)
            self.index += 1
        elif tokenText == "<":
            # Check if the next character is a "=" to identify less than or equal
            if self.index + 1 < len(self.source) and self.source[self.index + 1] == "=":
                tokenText += self.source[self.index + 1]
                self.index += 2
                token = Token(tokenText, TokenType.LEQ)
            else:
                token = Token(tokenText, TokenType.LTH)
                self.index += 1
        elif tokenText == "(":
            # Check if the next character is a "*" to identify a comment
            if self.index + 1 < len(self.source) and self.source[self.index + 1] == "*":
                # Read until the other "*)"
                self.index += 1
                while self.index < len(self.source) and tokenText.endswith("*)") == False:
                    tokenText += self.source[self.index]
                    self.index += 1
                token = Token(tokenText, TokenType.COM)
            else:
                token = Token(tokenText, TokenType.LPR)
                self.index += 1
        elif tokenText == ")":
            token = Token(tokenText, TokenType.RPR)
            self.index += 1
        else:
            self.index += 1
            while self.index < len(self.source) and self.source[self.index] != "\n" and self.source[self.index] != " " and self.source[self.index] != "=" and self.source[self.index] != "+" and self.source[self.index] != "-" and self.source[self.index] != "*" and self.source[self.index] != "/" and self.source[self.index] != "<" and self.source[self.index] != "(" and self.source[self.index] != ")":
                tokenText += self.source[self.index]
                self.index += 1
            
            if tokenText == "true":
                token = Token(tokenText, TokenType.TRU)
            elif tokenText == "false":
                token = Token(tokenText, TokenType.FLS)
            elif tokenText == "not":
                token = Token(tokenText, TokenType.NOT)
            elif tokenText.isdigit():
                token = Token(tokenText, TokenType.NUM)

        return token