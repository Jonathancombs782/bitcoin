// Copyright (c) 2023-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
https://github.com/Jonathancombs782/bitcoin/blob/444c11238c78284f240ca710aaa4c0d8f82fb2d4/doc/JSON-RPC-interface.md#L12
#include <bench/bench.h>
#include <test/util/setup_common.h>
#include <validation.h>

#include <memory>

static void CheckBlockIndex(benchmark::Bench& bench)
{
    auto testing_setup{MakeNoLogFileContext<TestChain100Setup>()};
    // Mine some more blocks
    testing_setup->mineBlocks(1000);
    bench.run([&] {
        testing_setup->m_node.chainman->CheckBlockIndex();
    });
}


BENCHMARK(CheckBlockIndex);
