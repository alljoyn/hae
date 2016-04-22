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

package org.alljoyn.smartspaces.haecontroller.activity.environment;

import android.view.View;
import android.view.ViewGroup;

import org.alljoyn.smartspaces.environment.TargetTemperature;
import org.alljoyn.smartspaces.haecontroller.activity.InterfaceActivity;
import org.alljoyn.smartspaces.haecontroller.view.MinMaxPropertyView;
import org.alljoyn.smartspaces.haecontroller.view.ReadOnlyPropertyView;
import org.alljoyn.smartspaces.haecontroller.view.ReadWritePropertyView;
import org.alljoyn.smartspaces.operation.Channel;

public class TargetTemperatureActivity extends InterfaceActivity {
    @Override
    protected void generatePropertyView(CustomView properties, CustomView methods) {
        View targetValueView = new MinMaxPropertyView(this, this.intf, "TargetValue", "C", "MinValue", "MaxValue", "StepValue");
        properties.addView(targetValueView);
    }
}
