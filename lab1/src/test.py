import unittest
from main import get_h
class Test(unittest.TestCase):
    def test_height(self):
        self.assertEqual(get_h([4, -1, 4, 1, 1], 5), 3)
        self.assertEqual(get_h([-1, 0, 4, 0, 3], 5), 4)
        self.assertEqual(get_h([11, 4, 6, 9, 9, 12, -1, 3, 2, 6, 7, 2, 7, 12], 13), 6)
        self.assertEqual(get_h([5, -1, 6, 2, 3, 4, 1, 4], 8), 7)
        self.assertEqual(get_h([-1], 1), 1)

if __name__ == '__main__':
    unittest.main()
