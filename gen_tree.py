import clang.cindex as CX
import sys

def printN(node: CX.Cursor):
    kind = f"{str(node.kind).removeprefix('CursorKind.')}"
    value = node.spelling
    range = str(node.extent.start.line) + ' ' + str(node.extent.start.column) + ' ' + str(node.extent.end.line) + ' ' + str(node.extent.end.column)
    if node.kind == CX.CursorKind.INTEGER_LITERAL:
        value = list(node.get_tokens())[0].spelling
    return f"{kind} {value} {range}"

node_cnt = 0

def traverse(node: CX.Cursor):
    children = list(node.get_children())
    
    print('%s' % (printN(node)))

    for child in children:
        traverse(child)
        
    print('RETURN')


index = CX.Index.create(excludeDecls=True)
tu = index.parse(sys.argv[1], args=['-std=c++14'])
traverse(tu.cursor)