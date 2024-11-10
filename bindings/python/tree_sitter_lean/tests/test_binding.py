import tree_sitter
import tree_sitter_lean


def test_can_load_grammar(self):
    tree_sitter.Language(tree_sitter_lean.language())
