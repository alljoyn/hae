# Copyright AllSeen Alliance. All rights reserved.
#
#    Permission to use, copy, modify, and/or distribute this software for any
#    purpose with or without fee is hereby granted, provided that the above
#    copyright notice and this permission notice appear in all copies.
#
#    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
#    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
#    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
#    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
#    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
#    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
#    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

import os

Import('env')

env['_ALLJOYN_HAE_'] = True
env['OBJDIR_SERVICES_HAE'] = env['OBJDIR'] + '/services/hae'

# Make config library and header file paths available to the global environment
env.Append(LIBPATH = '$DISTDIR/hae/lib');
env.Append(CPPPATH = '$DISTDIR/hae/inc');

if not env.has_key('_ALLJOYN_ABOUT_') and os.path.exists('../../core/alljoyn/services/about/SConscript'):
    env.SConscript('../../core/alljoyn/services/about/SConscript')

if 'cpp' in env['bindings'] and not env.has_key('_ALLJOYNCORE_') and os.path.exists('../../core/alljoyn/alljoyn_core/SConscript'):
   env.SConscript('../../core/alljoyn/alljoyn_core/SConscript')

if 'java' in env['bindings'] and not env.has_key('_ALLJOYN_JAVA_') and os.path.exists('../../core/alljoyn/alljoyn_java/SConscript'):
   env.SConscript('../../core/alljoyn/alljoyn_java/SConscript')

hae_env = env.Clone()

for b in hae_env['bindings']:
    if os.path.exists('%s/SConscript' % b):
        hae_env.VariantDir('$OBJDIR_SERVICES_HAE/%s' % b, b, duplicate = 0)

hae_env.SConscript(['$OBJDIR_SERVICES_HAE/%s/SConscript' % b for b in env['bindings'] if os.path.exists('%s/SConscript' % b) ],
                  exports = ['hae_env'])
