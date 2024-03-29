<?php
/**
 * PHPUnit
 *
 * Copyright (c) 2010-2013, Sebastian Bergmann <sb@sebastian-bergmann.de>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *   * Neither the name of Sebastian Bergmann nor the names of his
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @package    PHPUnit_MockObject
 * @author     Sebastian Bergmann <sb@sebastian-bergmann.de>
 * @copyright  2010-2013 Sebastian Bergmann <sb@sebastian-bergmann.de>
 * @license    http://www.opensource.org/licenses/BSD-3-Clause  The BSD
 *   3-Clause License
 * @link       http://github.com/sebastianbergmann/phpunit-mock-objects
 * @since      File available since Release 1.0.0
 */

/**
 * Invocation matcher which does not care about previous state from earlier
 * invocations.
 *
 * This abstract class can be implemented by matchers which does not care about
 * state but only the current run-time value of the invocation itself.
 *
 * @package    PHPUnit_MockObject
 * @author     Sebastian Bergmann <sb@sebastian-bergmann.de>
 * @copyright  2010-2013 Sebastian Bergmann <sb@sebastian-bergmann.de>
 * @license    http://www.opensource.org/licenses/BSD-3-Clause  The BSD
 *   3-Clause License
 * @version    Release: @package_version@
 * @link       http://github.com/sebastianbergmann/phpunit-mock-objects
 * @since      Class available since Release 1.0.0
 * @abstract
 */
abstract class PHPUnit_Framework_MockObject_Matcher_StatelessInvocation implements PHPUnit_Framework_MockObject_Matcher_Invocation {
  /**
   * Registers the invocation $invocation in the object as being invoked.
   * This will only occur after matches() returns true which means the
   * current invocation is the correct one.
   *
   * The matcher can store information from the invocation which can later
   * be checked in verify(), or it can check the values directly and throw
   * and exception if an expectation is not met.
   *
   * If the matcher is a stub it will also have a return value.
   *
   * @param  PHPUnit_Framework_MockObject_Invocation $invocation
   *         Object containing information on a mocked or stubbed method which
   *         was invoked.
   *
   * @return mixed
   */
  public function invoked(PHPUnit_Framework_MockObject_Invocation $invocation) {
  }

  /**
   * Checks if the invocation $invocation matches the current rules. If it does
   * the matcher will get the invoked() method called which should check if an
   * expectation is met.
   *
   * @param  PHPUnit_Framework_MockObject_Invocation $invocation
   *         Object containing information on a mocked or stubbed method which
   *         was invoked.
   *
   * @return bool
   */
  public function verify() {
  }
}
