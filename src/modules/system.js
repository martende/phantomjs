/*
 * CommonJS System/1.0
 * Spec: http://wiki.commonjs.org/wiki/System/1.0
 */
var fs = require('fs');

exports.platform = 'phantomjs';

exports.stdin = fs._addAsyncFuncsToFile(exports._stdin);
exports.stdout = fs._addAsyncFuncsToFile(exports._stdout);
exports.stderr = fs._addAsyncFuncsToFile(exports._stderr);