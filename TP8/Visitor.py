import sys
from abc import ABC, abstractmethod
from Expression import *
import Asm as AsmModule

class Visitor(ABC):
    """
    The visitor pattern consists of two abstract classes: the Expression and the
    Visitor. The Expression class defines on method: 'accept(visitor, args)'.
    This method takes in an implementation of a visitor, and the arguments that
    are passed from expression to expression. The Visitor class defines one
    specific method for each subclass of Expression. Each instance of such a
    subclasse will invoke the right visiting method.
    """
    @abstractmethod
    def visit_var(self, exp, arg):
        pass

    @abstractmethod
    def visit_bln(self, exp, arg):
        pass

    @abstractmethod
    def visit_num(self, exp, arg):
        pass

    @abstractmethod
    def visit_eql(self, exp, arg):
        pass

    @abstractmethod
    def visit_add(self, exp, arg):
        pass

    @abstractmethod
    def visit_sub(self, exp, arg):
        pass

    @abstractmethod
    def visit_mul(self, exp, arg):
        pass

    @abstractmethod
    def visit_div(self, exp, arg):
        pass

    @abstractmethod
    def visit_leq(self, exp, arg):
        pass

    @abstractmethod
    def visit_lth(self, exp, arg):
        pass

    @abstractmethod
    def visit_neg(self, exp, arg):
        pass

    @abstractmethod
    def visit_not(self, exp, arg):
        pass

    @abstractmethod
    def visit_let(self, exp, arg):
        pass

class EvalVisitor(Visitor):
    """
    The EvalVisitor class evaluates logical and arithmetic expressions. The
    result of evaluating an expression is the value of that expression. The
    inherited attribute propagated throughout visits is the environment that
    associates the names of variables with values.

    Examples:
    >>> e0 = Let('v', Add(Num(40), Num(2)), Mul(Var('v'), Var('v')))
    >>> e1 = Not(Eql(e0, Num(1764)))
    >>> ev = EvalVisitor()
    >>> e1.accept(ev, {})
    False

    >>> e0 = Let('v', Add(Num(40), Num(2)), Sub(Var('v'), Num(2)))
    >>> e1 = Lth(e0, Var('x'))
    >>> ev = EvalVisitor()
    >>> e1.accept(ev, {'x': 41})
    True
    """

    def check_type(self, val, expected_type):
        if not type(val) == expected_type:
            sys.exit("Type error")

    def visit_var(self, exp, env):
        # TODO: Implement this method!
        if exp.identifier in env:
            return env[exp.identifier]
        else:
            sys.exit("Def error")

    def visit_bln(self, exp, env):
        # TODO: Implement this method!
        return exp.bln

    def visit_num(self, exp, env):
        # TODO: Implement this method!
        return exp.num

    def visit_eql(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)

        if type(left_value) == int:
            self.check_type(right_value, int)
        elif type(left_value) == bool:
            self.check_type(right_value, bool)
        else:
            sys.exit("Type error")

        return left_value == right_value

    def visit_add(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)
        
        self.check_type(left_value, int)
        self.check_type(right_value, int)

        return left_value + right_value

    def visit_sub(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)

        self.check_type(left_value, int)
        self.check_type(right_value, int)

        return left_value - right_value

    def visit_mul(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)

        self.check_type(left_value, int)
        self.check_type(right_value, int)

        return left_value * right_value

    def visit_div(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)

        self.check_type(left_value, int)
        self.check_type(right_value, int)

        if right_value == 0:
            sys.exit("Division by zero error: erro que ocorre quando tentamos dividir por zero.")
        
        return left_value // right_value

    def visit_leq(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)

        self.check_type(left_value, int)
        self.check_type(right_value, int)

        return left_value <= right_value

    def visit_lth(self, exp, env):
        # TODO: Implement this method!
        left_value = exp.left.accept(self, env)
        right_value = exp.right.accept(self, env)

        self.check_type(left_value, int)
        self.check_type(right_value, int)

        return left_value < right_value

    def visit_neg(self, exp, env):
        # TODO: Implement this method!
        result = exp.exp.accept(self, env)
        
        self.check_type(result, int)

        return -result

    def visit_not(self, exp, env):
        # TODO: Implement this method!
        result = exp.exp.accept(self, env)

        self.check_type(result, bool)

        return not result

    def visit_let(self, exp, env):
        # TODO: Implement this method!
        def_val = exp.exp_def.accept(self, env)
        updated_env = dict(env)
        updated_env[exp.identifier] = def_val
        return exp.exp_body.accept(self, updated_env)
    
    def visit_if_then_else(self, exp, env):
        condition = exp.cond.accept(self, env)

        self.check_type(condition, bool)

        if condition:
            return exp.e0.accept(self, env)
        else:
            return exp.e1.accept(self, env)
    
    def visit_and(self, exp, env):
        left = exp.left.accept(self, env)
        self.check_type(left, bool)

        if left:
            right = exp.right.accept(self, env)
            self.check_type(right, bool)
            return right
        
        return False
    
    def visit_or(self, exp, env):
        left = exp.left.accept(self, env)
        self.check_type(left, bool)

        if left:
            return True
        
        right = exp.right.accept(self, env)
        self.check_type(right, bool)
        return right


class UseDefVisitor(Visitor):
    """
    The UseDefVisitor class reports the use of undefined variables. It takes
    as input an environment of defined variables, and produces, as output,
    the set of all the variables that are used without being defined.

    Examples:
    >>> e0 = Let('v', Add(Num(40), Num(2)), Mul(Var('v'), Var('v')))
    >>> e1 = Not(Eql(e0, Num(1764)))
    >>> ev = UseDefVisitor()
    >>> len(e1.accept(ev, set()))
    0

    >>> e0 = Let('v', Add(Num(40), Num(2)), Sub(Var('v'), Num(2)))
    >>> e1 = Lth(e0, Var('x'))
    >>> ev = UseDefVisitor()
    >>> len(e1.accept(ev, set()))
    1

    >>> e = Let('v', Add(Num(40), Var('v')), Sub(Var('v'), Num(2)))
    >>> ev = UseDefVisitor()
    >>> len(e.accept(ev, set()))
    1

    >>> e1 = Let('v', Add(Num(40), Var('v')), Sub(Var('v'), Num(2)))
    >>> e0 = Let('v', Num(3), e1)
    >>> ev = UseDefVisitor()
    >>> len(e0.accept(ev, set()))
    0
    """
    # TODO: Implement all the 13 methods of the visitor.
    def visit_var(self, exp, env):
        if exp.identifier not in env:
            return set([exp.identifier])
        return set()
    
    def visit_bln(self, exp, env):
        return set()
    
    def visit_num(self, exp, env):
        return set()
    
    def visit_eql(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_add(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_sub(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_mul(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_div(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_leq(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_lth(self, exp, env):
        left_uses = exp.left.accept(self, env)
        right_uses = exp.right.accept(self, env)
        return left_uses | right_uses
    
    def visit_neg(self, exp, env):
        return exp.exp.accept(self, env)
    
    def visit_not(self, exp, env):
        return exp.exp.accept(self, env)
    
    def visit_let(self, exp, env):
        def_uses = exp.exp_def.accept(self, env)
        updated_env = dict(env)
        updated_env[exp.identifier] = None
        body_uses = exp.exp_body.accept(self, updated_env)
        return def_uses | body_uses

def safe_eval(exp):
    """
    This method applies one simple semantic analysis onto an expression, before
    evaluating it: it checks if the expression contains free variables, there
    is, variables used without being defined.

    Example:
    >>> e0 = Let('v', Add(Num(40), Num(2)), Mul(Var('v'), Var('v')))
    >>> e1 = Not(Eql(e0, Num(1764)))
    >>> safe_eval(e1)
    Value is False

    >>> e0 = Let('v', Add(Num(40), Num(2)), Sub(Var('v'), Num(2)))
    >>> e1 = Lth(e0, Var('x'))
    >>> safe_eval(e1)
    Error: expression contains undefined variables.
    """
    # TODO: Implement this method!
    use_def_visitor = UseDefVisitor()
    undefined_vars = exp.accept(use_def_visitor, set())
    if len(undefined_vars) > 0:
        print("Error: expression contains undefined variables.")
    else:
        eval_visitor = EvalVisitor()
        value = exp.accept(eval_visitor, {})
        print(f"Value is {value}")

class CtrGenVisitor(Visitor):
    """
    This visitor creates constraints for a type-inference engine. Basically,
    it traverses the abstract-syntax tree of expressions, producing pairs like
    (type0, type1) on the way. A pair like (type0, type1) indicates that these
    two type variables are the same.

    Examples:
        >>> e = Let('v', Num(40), Let('w', Num(2), Add(Var('v'), Var('w'))))
        >>> ev = CtrGenVisitor()
        >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
        ["('TV_1', 'TV_2')", "('TV_2', 'TV_3')", "('v', <class 'int'>)", "('w', <class 'int'>)", "(<class 'int'>, 'TV_3')", "(<class 'int'>, 'v')", "(<class 'int'>, 'w')"]
    """

    def __init__(self):
        self.fresh_type_counter = 0

    def fresh_type_var(self):
        """
        Create a new type var using the current value of the fresh_type_counter.
        Two successive calls to this method will return different type names.
        Notice that the name of a type variable is always TV_x, where x is
        some integer number. That means that probably we would run into
        errors if someone declares a variable called, say, TV_1 or TV_2, as in
        "let TV_1 <- 1 in TV_1 end". But you can assume that such would never
        happen in the test cases. In practice, we should define a new class
        to represent type variables. But let's keep the implementation as
        simple as possible.

        Example:
            >>> ev = CtrGenVisitor()
            >>> [ev.fresh_type_var(), ev.fresh_type_var()]
            ['TV_1', 'TV_2']
        """
        self.fresh_type_counter += 1
        return f"TV_{self.fresh_type_counter}"

    """
    The CtrGenVisitor class creates constraints that, once solved, will give
    us the type of the different variables. Every accept method takes in
    two arguments (in addition to self):
    
    exp: is the expression that is being analyzed.
    type_var: that is a name that works as a placeholder for the type of the
    expression. Whenever we visit a new expression, we create a type variable
    to represent its type (you can do that with the method fresh_type_var).
    The only exception is the type of Var expressions. In this case, the type
    of a Var expression is the identifier of that expression.
    """

    def visit_var(self, exp, type_var):
        """
        Example:
            >>> e = Var('v')
            >>> ev = CtrGenVisitor()
            >>> e.accept(ev, ev.fresh_type_var())
            {('v', 'TV_1')}
        """
        return {(exp.identifier, type_var)}

    def visit_bln(self, exp, type_var):
        """
        Example:
            >>> e = Bln(True)
            >>> ev = CtrGenVisitor()
            >>> e.accept(ev, ev.fresh_type_var())
            {(<class 'bool'>, 'TV_1')}
        """
        return {(type(True), type_var)}

    def visit_num(self, exp, type_var):
        """
        Example:
            >>> e = Num(1)
            >>> ev = CtrGenVisitor()
            >>> e.accept(ev, ev.fresh_type_var())
            {(<class 'int'>, 'TV_1')}
        """
        return {(type(1), type_var)}

    def visit_eql(self, exp, type_var):
        """
        Example:
            >>> e = Eql(Num(1), Bln(True))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'bool'>, 'TV_2')", "(<class 'int'>, 'TV_2')"]

        Notice that if we have repeated constraints, they only appear once in
        the set of constraints (after all, it's a set!). As an example, we
        would have two occurrences of the pair (TV_2, int) in the following
        example:
            >>> e = Eql(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'int'>, 'TV_2')"]
        """
        # TODO: Implement this method!
        fresh_type_var = self.fresh_type_var()
        right_constraint = exp.right.accept(self, fresh_type_var)
        left_constraint = exp.left.accept(self, fresh_type_var)
        return left_constraint | right_constraint | {(type(False), type_var)}

    def visit_and(self, exp, type_var):
        """
        Example:
            >>> e = And(Bln(False), Bln(True))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'bool'>, <class 'bool'>)"]

        In the above example, notice that we ended up getting a trivial
        constraint, e.g.: (<class 'bool'>, <class 'bool'>). That's alright:
        don't worry about these trivial constraints at this point. We can
        remove them from the set of constraints later on, when we try to
        solve them.
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(False))
        right_constraint = exp.right.accept(self, type(False))
        return left_constraint | right_constraint | {(type(False), type_var)}

    def visit_or(self, exp, type_var):
        """
        Example:
            >>> e = Or(Bln(False), Bln(True))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'bool'>, <class 'bool'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(False))
        right_constraint = exp.right.accept(self, type(False))
        return left_constraint | right_constraint | {(type(False), type_var)}

    def visit_add(self, exp, type_var):
        """
        Example:
            >>> e = Add(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'int'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(1))
        right_constraint = exp.right.accept(self, type(1))
        return left_constraint | right_constraint | {(type(1), type_var)}

    def visit_sub(self, exp, type_var):
        """
        Example:
            >>> e = Sub(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'int'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(1))
        right_constraint = exp.right.accept(self, type(1))
        return left_constraint | right_constraint | {(type(1), type_var)}

    def visit_mul(self, exp, type_var):
        """
        Example:
            >>> e = Mul(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'int'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(1))
        right_constraint = exp.right.accept(self, type(1))
        return left_constraint | right_constraint | {(type(1), type_var)}

    def visit_div(self, exp, type_var):
        """
        Example:
            >>> e = Div(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'int'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(1))
        right_constraint = exp.right.accept(self, type(1))
        return left_constraint | right_constraint | {(type(1), type_var)}

    def visit_leq(self, exp, type_var):
        """
        Example:
            >>> e = Leq(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(1))
        right_constraint = exp.right.accept(self, type(1))
        return left_constraint | right_constraint | {(type(False), type_var)}

    def visit_lth(self, exp, type_var):
        """
        Example:
            >>> e = Lth(Num(1), Num(2))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        left_constraint = exp.left.accept(self, type(1))
        right_constraint = exp.right.accept(self, type(1))
        return left_constraint | right_constraint | {(type(False), type_var)}

    def visit_neg(self, exp, type_var):
        """
        Example:
            >>> e = Neg(Num(1))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'int'>, 'TV_1')", "(<class 'int'>, <class 'int'>)"]
        """
        # TODO: Implement this method!
        constraint = exp.exp.accept(self, type(1))
        return constraint | {(type(1), type_var)}

    def visit_not(self, exp, type_var):
        """
        Example:
            >>> e = Not(Bln(True))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["(<class 'bool'>, 'TV_1')", "(<class 'bool'>, <class 'bool'>)"]
        """
        # TODO: Implement this method!
        constraint = exp.exp.accept(self, type(False))
        return constraint | {(type(False), type_var)}

    def visit_let(self, exp, type_var):
        """
        Example:
            >>> e = Let('v', Num(42), Var('v'))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["('TV_1', 'TV_2')", "('v', 'TV_2')", "(<class 'int'>, 'v')"]
        """
        # TODO: Implement this method!
        def_constraint = exp.exp_def.accept(self, exp.identifier)
        fresh_type = self.fresh_type_var()
        body_constraint = exp.exp_body.accept(self, fresh_type)
        return def_constraint | body_constraint | {(type_var, fresh_type)}

    def visit_if_then_else(self, exp, type_var):
        """
        Example:
            >>> e = IfThenElse(Bln(True), Num(42), Num(30))
            >>> ev = CtrGenVisitor()
            >>> sorted([str(ct) for ct in e.accept(ev, ev.fresh_type_var())])
            ["('TV_1', 'TV_2')", "(<class 'bool'>, <class 'bool'>)", "(<class 'int'>, 'TV_2')"]
        """
        # TODO: Implement this method!
        condition_constraint = exp.cond.accept(self, type(False))
        fresh_type = self.fresh_type_var()
        true_branch_constraint = exp.e0.accept(self, fresh_type)
        false_branch_constraint = exp.e1.accept(self, fresh_type)
        return condition_constraint | true_branch_constraint | false_branch_constraint | {(type_var, fresh_type)}
    
class GenVisitor(Visitor):
    """
    The GenVisitor class compiles arithmetic expressions into a low-level
    language.
    """

    def __init__(self):
        self.next_var_counter = 0

    def next_var_name(self):
        self.next_var_counter += 1
        return f"v{self.next_var_counter}"

    def visit_var(self, exp, prog):
        """
        Usage:
            >>> e = Var('x')
            >>> p = AsmModule.Program({"x":1}, [])
            >>> g = GenVisitor()
            >>> v = e.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            1
        """
        return exp.identifier

    def visit_bln(self, exp, prog):
        """
        Usage:
            >>> e = Bln(True)
            >>> p = AsmModule.Program({}, [])
            >>> g = GenVisitor()
            >>> v = e.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            1

            >>> e = Bln(False)
            >>> p = AsmModule.Program({}, [])
            >>> g = GenVisitor()
            >>> v = e.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            0
        """
        # TODO: Implement this method.
        register = self.next_var_name()
        val = None
        if exp.bln:
            val = 1
        else:
            val = 0
        prog.add_inst(AsmModule.Addi(register, "x0", val))
        return register

    def visit_num(self, exp, prog):
        """
        Usage:
            >>> e = Num(13)
            >>> p = AsmModule.Program({}, [])
            >>> g = GenVisitor()
            >>> v = e.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            13
        """
        # TODO: Implement this method.
        register = self.next_var_name()
        prog.add_inst(AsmModule.Addi(register, "x0", exp.num))
        return register

    def compute_equality(self, left_register, right_register, prog):
        delta = self.next_var_name()
        condition1 = self.next_var_name()
        condition2 = self.next_var_name()
        equal_register = self.next_var_name()

        prog.add_inst(AsmModule.Sub(delta, left_register, right_register))
        prog.add_inst(AsmModule.Slti(condition1, delta, 1))
        prog.add_inst(AsmModule.Slti(condition2, delta, 0))
        prog.add_inst(AsmModule.Xor(equal_register, condition1, condition2))
        return equal_register

    def visit_eql(self, exp, prog):
        """
        >>> e = Eql(Num(13), Num(13))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Eql(Num(13), Num(10))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Eql(Num(-1), Num(1))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0
        """
        # TODO: Implement this method.
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        return self.compute_equality(left, right, prog)

    def visit_add(self, exp, prog):
        """
        >>> e = Add(Num(13), Num(-13))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Add(Num(13), Num(10))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        23
        """
        # TODO: Implement this method (see the example in the lab's page).
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Add(result_register, left, right))
        return result_register

    def visit_sub(self, exp, prog):
        """
        >>> e = Sub(Num(13), Num(-13))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        26

        >>> e = Sub(Num(13), Num(10))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        3
        """
        # TODO: Implement this method.
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Sub(result_register, left, right))
        return result_register

    def visit_mul(self, exp, prog):
        """
        >>> e = Mul(Num(13), Num(2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        26

        >>> e = Mul(Num(13), Num(10))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        130
        """
        # TODO: Implement this method.
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Mul(result_register, left, right))
        return result_register

    def visit_div(self, exp, prog):
        """
        >>> e = Div(Num(13), Num(2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        6

        >>> e = Div(Num(13), Num(10))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1
        """
        # TODO: Implement this method.
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Div(result_register, left, right))
        return result_register

    def visit_leq(self, exp, prog):
        """
        >>> e = Leq(Num(3), Num(2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Leq(Num(3), Num(3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Leq(Num(2), Num(3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Leq(Num(-3), Num(-2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Leq(Num(-3), Num(-3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Leq(Num(-2), Num(-3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0
        """
        # TODO: Implement this method.
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        less_register = self.next_var_name()
        equal_register = self.compute_equality(left, right, prog)
        prog.add_inst(AsmModule.Slt(less_register, left, right))
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Add(result_register, less_register, equal_register))
        return result_register

    def visit_lth(self, exp, prog):
        """
        >>> e = Lth(Num(3), Num(2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Lth(Num(3), Num(3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Lth(Num(2), Num(3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1
        """
        # TODO: Implement this method.
        left = exp.left.accept(self, prog)
        right = exp.right.accept(self, prog)
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Slt(result_register, left, right))
        return result_register

    def visit_neg(self, exp, prog):
        """
        >>> e = Neg(Num(3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        -3

        >>> e = Neg(Num(0))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Neg(Num(-3))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        3
        """
        # TODO: Implement this method.
        value_register = exp.exp.accept(self, prog)
        result_register = self.next_var_name()
        prog.add_inst(AsmModule.Sub(result_register, "x0", value_register))
        return result_register

    def visit_not(self, exp, prog):
        """
        >>> e = Not(Bln(True))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Not(Bln(False))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Not(Num(0))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        1

        >>> e = Not(Num(-2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0

        >>> e = Not(Num(2))
        >>> p = AsmModule.Program({}, [])
        >>> g = GenVisitor()
        >>> v = e.accept(g, p)
        >>> p.eval()
        >>> p.get_val(v)
        0
        """
        # TODO: Implement this method.
        value_register = exp.exp.accept(self, prog)
        return self.compute_equality(value_register, "x0", prog)

    def visit_let(self, exp, prog):
        """
        Usage:
            >>> e = Let('v', Not(Bln(False)), Var('v'))
            >>> p = AsmModule.Program({}, [])
            >>> g = GenVisitor()
            >>> v = e.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            1

            >>> e = Let('v', Num(2), Add(Var('v'), Num(3)))
            >>> p = AsmModule.Program({}, [])
            >>> g = GenVisitor()
            >>> v = e.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            5

            >>> e0 = Let('x', Num(2), Add(Var('x'), Num(3)))
            >>> e1 = Let('y', e0, Mul(Var('y'), Num(10)))
            >>> p = AsmModule.Program({}, [])
            >>> g = GenVisitor()
            >>> v = e1.accept(g, p)
            >>> p.eval()
            >>> p.get_val(v)
            50
        """
        # TODO: Implement this method.
        def_value = exp.exp_def.accept(self, prog)
        prog.add_inst(AsmModule.Add(exp.identifier, def_value, "x0"))
        body_value = exp.exp_body.accept(self, prog)
        return body_value