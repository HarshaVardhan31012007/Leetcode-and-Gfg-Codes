const MAXN = 100_000
var FLAT [MAXN]uint32
var SUM [MAXN]int
var seen [MAXN + 1]uint16
var gen uint16

func canPartitionGrid(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	if m == 1 {
		totalsum := 0
		for j := range grid[0] {
			totalsum += grid[0][j]
		}
		return solve1D(grid[0], totalsum)
	}
	if n == 1 {
		totalsum := 0
		flat := SUM[:m]
		for i := range m {
			flat[i] = grid[i][0]
			totalsum += grid[i][0]
		}
		return solve1D(flat, totalsum)
	}
	// flatten the grid and calculate sums and maxv
	flat := FLAT[:0]
	linesum := SUM[:m]
	totalsum, _maxv := 0, 0
	for i := range m {
		sum := 0
		for j := range n {
			flat = append(flat, uint32(grid[i][j]))
			_maxv = max(_maxv, grid[i][j])
			sum += grid[i][j]
		}
		linesum[i] = sum
		totalsum += sum
	}
    maxv := uint32(_maxv)
	if solve(flat, linesum, totalsum, -1, 1, maxv) || solve(flat, linesum, totalsum, m, -1, maxv) {
		return true
	}
	// transpose
	flat, linesum = FLAT[:0], SUM[:n]
	for j := range n {
		sum := 0
		for i := range m {
			flat = append(flat, uint32(grid[i][j]))
			sum += grid[i][j]
		}
		linesum[j] = sum
	}
	return solve(flat, linesum, totalsum, -1, 1, maxv) || solve(flat, linesum, totalsum, n, -1, maxv)
}

func solve1D(arr []int, totalsum int) bool {
	n := len(arr)
	pref, first, last := 0, arr[0], arr[n-1]
	for i := range n - 1 {
		pref += arr[i]
		suff := totalsum - pref
		if pref == suff {
			return true
		} else if pref > suff {
			diff := pref - suff
			if first == diff || arr[i] == diff {
				return true
			}
		} else {
			diff := suff - pref
			if arr[i+1] == diff || last == diff {
				return true
			}
		}
	}
	return false
}

func solve(flat []uint32, linesum []int, totalsum, idx, step int, maxv uint32) bool {
	rows := len(linesum)
	cols := len(flat) / rows
	gen++
	var pref int
	for i := range rows - 1 {
		idx += step
		pref += linesum[idx]
		offset := idx * cols
		// mark values from this row as seen
		for j := range cols {
			seen[flat[offset+j]] = gen
		}
		suff := totalsum - pref
		// still need to collect more numbers
		if pref < suff {
			continue
		}
		// perfect split without removing number
		if pref == suff {
			return true
		}
		diff := uint32(pref - suff)
		// no removal can balance the splits anymore
		if diff > maxv {
			break
		}
		// potential split by removing number
		// check if it doesn't disconnect the split
		if seen[diff] == gen && i > 0 || flat[offset] == diff || flat[offset+cols-1] == diff {
			return true
		}
	}
	return false
}