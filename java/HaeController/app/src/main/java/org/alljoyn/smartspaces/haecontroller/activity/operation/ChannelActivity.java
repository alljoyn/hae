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

package org.alljoyn.smartspaces.haecontroller.activity.operation;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import org.alljoyn.bus.Variant;
import org.alljoyn.bus.annotation.BusSignalHandler;
import org.alljoyn.smartspaces.haecontroller.activity.InterfaceActivity;
import org.alljoyn.smartspaces.haecontroller.logic.IntentKeys;
import org.alljoyn.smartspaces.haecontroller.view.MethodView;
import org.alljoyn.smartspaces.haecontroller.view.ReadOnlyPropertyView;
import org.alljoyn.smartspaces.haecontroller.view.SupportedValuesPropertyView;
import org.alljoyn.smartspaces.operation.Channel;

import java.util.Map;

public class ChannelActivity extends InterfaceActivity {

    @Override
    protected void generatePropertyView(CustomView properties, CustomView methods) {
        View channelIdView = new SupportedValuesPropertyView(this, this.intf, "ChannelId", null, 0, "getChannelList", 0, 100);
        properties.addView(channelIdView);

        View totalNumberOfChannelsView = new ReadOnlyPropertyView(this, this.intf, "TotalNumberOfChannels", null);
        properties.addView(totalNumberOfChannelsView);

        View getChannelListView = new MethodView(this, this.intf, "GetChannelList", "startingRecord", "numRecords");
        methods.addView(getChannelListView);
    }

    @BusSignalHandler(iface = "org.alljoyn.smartspaces.operation.Channel", signal = "ChannelListChanged")
    public void channelListChanged() {
        notifyEvent("ChannelListChanged");
    }
}
