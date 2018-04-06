/*
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

package org.alljoyn.smartspaces.operation;

import org.alljoyn.bus.annotation.BusInterface;
import org.alljoyn.bus.annotation.BusMethod;
import org.alljoyn.bus.annotation.BusProperty;
import org.alljoyn.bus.annotation.Secure;
import org.alljoyn.bus.BusException;

@BusInterface(name="org.alljoyn.SmartSpaces.Operation.RobotCleaningCyclePhase", descriptionLanguage="en")
@Secure
public interface RobotCleaningCyclePhase {
/*
    public class CyclePhaseDescriptor {
        @Position(0)
        @Signature("y")
        public byte phase;
        @Position(1)
        @Signature("s")
        public String name;
        @Position(2)
        @Signature("s")
        public String description;

        @Override
        public String toString() {
            return "[" + " phase=" + String.valueOf(phase) + " name=" + "\"" + name + "\"" + " description=" + "\"" + description + "\"" + " ]";
        }
    }
*/
    @BusProperty(annotation=BusProperty.ANNOTATE_EMIT_CHANGED_SIGNAL, signature="q")
    public short getVersion();

    @BusProperty(annotation=BusProperty.ANNOTATE_EMIT_CHANGED_SIGNAL, signature="y")
    public byte getCyclePhase();

    @BusProperty(annotation=BusProperty.ANNOTATE_EMIT_CHANGED_SIGNAL, signature="ay")
    public byte[] getSupportedCyclePhases();

    @BusMethod(name="GetVendorPhasesDescription", signature="s", replySignature="a(yss)")
    public CyclePhaseDescriptor[] getVendorPhasesDescription(String languageTag) throws BusException;

}