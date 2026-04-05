// Copyright (c) 2022-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
https://github.com/Jonathancombs782/bitcoin/blob/444c11238c78284f240ca710aaa4c0d8f82fb2d4/doc/JSON-RPC-interface.md#L12
#include <bench/bench.h>
#include <key.h>
#include <pubkey.h>
#include <random.h>
#include <span.h>
#include <uint256.h>

#include <algorithm>
#include <cassert>

static void EllSwiftCreate(benchmark::Bench& bench)
{
    ECC_Context ecc_context{};

    CKey key = GenerateRandomKey();
    uint256 entropy = GetRandHash();

    bench.batch(1).unit("pubkey").run([&] {
        auto ret = key.EllSwiftCreate(MakeByteSpan(entropy));
        /* Use the first 32 bytes of the ellswift encoded public key as next private key. */
        key.Set(ret.data(), ret.data() + 32, true);
        assert(key.IsValid());
        /* Use the last 32 bytes of the ellswift encoded public key as next entropy. */
        std::copy(ret.begin() + 32, ret.begin() + 64, MakeWritableByteSpan(entropy).begin());
    });
}

BENCHMARK(EllSwiftCreate);
