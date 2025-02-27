/*
 * Copyright (c) 2020-2023 Estonian Information System Authority
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "LatEIDIDEMIACommon.hpp"

namespace electronic_id
{

class LatEIDIDEMIAV2 : public LatEIDIDEMIACommon
{
public:
    explicit LatEIDIDEMIAV2(pcsc_cpp::SmartCard::ptr _card);
    ~LatEIDIDEMIAV2() override;
    PCSC_CPP_DISABLE_COPY_MOVE(LatEIDIDEMIAV2);

private:
    JsonWebSignatureAlgorithm authSignatureAlgorithm() const override;

    std::string name() const override { return "LatEID IDEMIA v2"; }

    const std::set<SignatureAlgorithm>& supportedSigningAlgorithms() const override;
    SignatureAlgorithm signingSignatureAlgorithm() const override;

    void selectAuthSecurityEnv() const override;
    pcsc_cpp::byte_type selectSignSecurityEnv() const override;

    struct Private;
    std::unique_ptr<Private> data;
};

} // namespace electronic_id
