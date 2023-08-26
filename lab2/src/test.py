import unittest
from main import merge
class Test(unittest.TestCase):
     def test_arr(self):
         res1 = merge([0, 1, 2], {0: 100, 1: 200, 2: 300})
         self.assertEqual(res1, [0, 1, 2])
         res2 = merge([0, 1, 2], {0: 35, 1: -200, 2: 1})
         self.assertEqual(res2, [1, 2, 0])
         res2 = merge([0, 1, 2, 3], {0: 3, 1: -200, 2: 1, 3: -9})
         self.assertEqual(res2, [1, 3, 2, 0])
         res2 = merge([0, 1, 2], {0: 1, 1: -35, 2: -35})
         self.assertEqual(res2, [1, 2, 0])

if __name__ == '__main__':
    unittest.main()

