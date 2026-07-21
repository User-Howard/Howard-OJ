class Solution {
    func maxActiveSectionsAfterTrade(_ s: String) -> Int {
        let runs = s.chunked(by: { $0 == $1 }).map(\.count)

        let startsWithOne = s.first == "1"
        let isOneBlock = { (i: Int) in startsWithOne ? i % 2 == 0 : i % 2 == 1 }

        let result = runs.enumerated()
            .filter { isOneBlock($0.offset) }
            .reduce(0) { $0 + $1.element }

        let zeroBlocks = runs.enumerated()
            .filter { !isOneBlock($0.offset) }
            .map(\.element)

        let maxGain = zeroBlocks
            .adjacentPairs()
            .map { $0 + $1}
            .max() ?? 0

        return result + maxGain
    }
}
