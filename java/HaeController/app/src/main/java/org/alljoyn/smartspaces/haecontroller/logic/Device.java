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

package org.alljoyn.smartspaces.haecontroller.logic;

import org.alljoyn.bus.AboutObjectDescription;
import org.alljoyn.bus.BusObject;
import org.alljoyn.bus.PropertiesChangedListener;
import org.alljoyn.bus.Status;
import org.alljoyn.bus.annotation.Position;
import org.alljoyn.bus.annotation.Signature;

import java.beans.PropertyChangeListener;
import java.util.UUID;

public interface Device {
    class DeviceTypeDescription {
        @Position(0)
        @Signature("u")
        public int deviceType;

        @Position(1)
        @Signature("o")
        public String objectPath;
    }
    static class DeviceType {
        static final int ROOT = 0;
        static final int OTHER                = 1;
        static final int REFRIGERATOR         = 2;
        static final int FREEZER              = 3;
        static final int ICE_MAKER            = 4;
        static final int AIR_CONDIRIONER      = 5;
        static final int THERMOSTAT           = 6;
        static final int HUMIDIFIER           = 7;
        static final int DEHUMIDIFIER         = 8;
        static final int AIR_PURIFIER         = 9;
        static final int ELECTRIC_FAN         = 10;
        static final int AIR_QUALITY_MONITOR  = 11;
        static final int CLOTHES_WASHER       = 12;
        static final int CLOTHES_DRYER        = 13;
        static final int CLOTHES_WASHER_DRYER = 14;
        static final int DISH_WASHER          = 15;
        static final int ROBOT_CLEANER        = 16;
        static final int OVEN                 = 17;
        static final int COOKER_HOOD          = 18;
        static final int COOKTOP              = 19;
        static final int FOOD_PROBE           = 20;
        static final int TELEVISION           = 21;
        static final int SET_TOP_BOX          = 22;
    };

    static class AboutDataKeys {
        static final String COUNTRY_OF_PRODUCTION   = "CountryOfProduction";
        static final String CORPORATE_BRAND         = "CorporateBrand";
        static final String PRODUCT_BRAND           = "ProductBrand";
        static final String LOCATION                = "Location";
        static final String DEVICE_TYPE_DESCRIPTION = "DeviceTypeDescription";
    }

    public String getName();
    public String getFriendlyName();
    public UUID getId();
    public DeviceTypeDescription[] getDeviceTypeDescriptions();
    public AboutObjectDescription[] getAboutObjectDescriptions();

    public Object getInterface(String objPath, String intfName);

    public Status registerSignal(BusObject obj);
    public Status registerPropertiesChangedSignal(PropertiesChangedListener listener);

    public void unregisterSignal(BusObject obj);
    public void unregisterPropertiesChangedSignal(PropertiesChangedListener listener);
}
