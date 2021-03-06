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

package org.alljoyn.cdmcontroller.logic;

import android.content.Context;

import org.alljoyn.bus.BusObject;
import org.alljoyn.bus.Status;

import java.util.Collection;
import java.util.UUID;

public abstract class DeviceManager {
    protected Context context;
    private static DeviceManager instance = null;

    public static DeviceManager getInstance() {
        return instance;
    }

    protected DeviceManager(Context c) {
        this.context = c;
        instance = this;
    }

    public abstract Device getDevice(UUID id);

    public abstract Collection<Device> getDevices();

    public abstract void registerBusObject(BusObject busObject, String objPath);

    public abstract Status registerSignalHandlers(Object handler);

    public abstract void unregisterSignalHandlers(Object handler);
}
