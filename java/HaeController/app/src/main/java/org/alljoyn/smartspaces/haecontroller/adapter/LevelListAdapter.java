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

package org.alljoyn.smartspaces.haecontroller.adapter;

import android.content.Context;
import android.util.SparseArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import org.alljoyn.smartspaces.haecontroller.R;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class LevelListAdapter extends BaseAdapter {
    public class Item {
        public int level = 0;
        public int icon = 0;
        public String title = "";
        public String detailInfo = "";
        public Item parent = null;

        public Item(Item parent, int level, int icon, String title, String detailInfo) {
            this.parent = parent;
            this.level = level;
            this.icon = icon;
            this.title = title;
            this.detailInfo = detailInfo;
        }
    }

    private SparseArray<Item> currentItem = new SparseArray<Item>();

    private ArrayList<Item> itemList = new ArrayList<Item>();

    private Context context;
    private View rowView = null;
    private LayoutInflater layoutInflater = null;

    private Map<String, InterfaceAdapter> adapterMap = new HashMap<String, InterfaceAdapter>();

    public LevelListAdapter(Context context) {
        this.context = context;
        this.layoutInflater = LayoutInflater.from(context);
    }

    public void setLayoutInflator(LayoutInflater layoutInflater) {
        this.layoutInflater = layoutInflater;
    }

    public void foldItem(int position) {

    }

    public boolean add(int level, int icon, String title, String description) {
        assert (level < 2);
        Item parent = null;
        if (level > 0)
            parent = this.currentItem.get(level-1);
        Item current = new Item(parent, level, icon, title, description);
        this.currentItem.put(level, current);
        return this.itemList.add(current);
    }


    @Override
    public int getCount() {
        return itemList.size();
    }

    @Override
    public Item getItem(int position) {
        return itemList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return this.itemList.get(position).hashCode();
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        this.rowView = layoutInflater.inflate(R.layout.level_list_item_info, parent, false);

        TextView titleView = (TextView) this.rowView.findViewById(R.id.title);
        TextView descView = (TextView) this.rowView.findViewById(R.id.description);

        Item item = this.getItem(position);
        if (item.level == 0) {
            this.rowView.setBackgroundColor(this.rowView.getResources().getColor(R.color.item_color2));
            titleView.setText(item.title);
            descView.setVisibility(View.GONE);
        } else if (item.level == 1) {
            this.rowView.setBackgroundColor(this.rowView.getResources().getColor(R.color.item_color));
            descView.setText(item.title);
            titleView.setVisibility(View.GONE);
        }
        return rowView;
    }
}
