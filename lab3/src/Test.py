import unittest
from main import process
from main import siftdown
class Test(unittest.TestCase):
     def test_arr(self):
         res1 = process([244, 7, 1234, 1, 7, 30], [[0, 0], [0, 1], [0, 2]])
         self.assertEqual(res1, [[0, 0], [1, 0], [2, 0], [1, 7], [1, 8], [1, 15]])

         res2 = process([8, 7, 6, 5, 4, 3, 8], [[0, 0], [0, 1]])
         self.assertEqual(res2, [[0, 0], [1, 0], [1, 7], [0, 8], [0, 13], [1, 13], [1, 16]])

         res3 = process([3, 7], [[0, 0], [0, 1], [0, 2], [0, 3], [0, 4], [0, 5]])
         self.assertEqual(res3, [[0, 0], [1, 0]])

         res4 = process([6, 4, 9], [[0, 0], [0, 1], [0, 2], [0, 3], [0, 4]])
         self.assertEqual(res4, [[0, 0], [1, 0], [2, 0]])

if __name__ == '__main__':
    unittest.main()
