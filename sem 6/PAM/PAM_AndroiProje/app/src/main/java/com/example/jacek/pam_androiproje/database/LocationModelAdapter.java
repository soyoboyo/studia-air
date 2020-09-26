package com.example.jacek.pam_androiproje.database;

import android.content.Context;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.example.jacek.pam_androiproje.R;
import com.example.jacek.pam_androiproje.database.room.LocationModel;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class LocationModelAdapter extends ArrayAdapter<LocationModel> {

    private int layoutResourceId;
    private Context context;
    private List<LocationModel> locations = new ArrayList<>();

    public LocationModelAdapter(@NonNull Context context, ArrayList<LocationModel> list) {
        super(context, 0, list);
        this.context = context;
        locations = list;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        View listItem = convertView;
        if (listItem == null) {
            LayoutInflater inflater = (LayoutInflater) getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            listItem = inflater.inflate(R.layout.row, parent, false);
        }

        LocationModel item = locations.get(position);

        TextView name = (TextView) listItem.findViewById(R.id.rowTextViewName);
        TextView address = (TextView) listItem.findViewById(R.id.rowTextViewAddress);
        TextView website = (TextView) listItem.findViewById(R.id.rowTextViewWebsite);
        TextView note = (TextView) listItem.findViewById(R.id.rowTextViewNote);
        TextView rating = (TextView) listItem.findViewById(R.id.rowTextViewRating);
        TextView visited = (TextView) listItem.findViewById(R.id.rowTextViewVisited);

        name.setText(item.getName());
        address.setText("Address: " + item.getAddress());
        website.setText("WWW: " + item.getWebsite());
        note.setText("Note: " + item.getNote());
        DecimalFormat decimalFormat = new DecimalFormat("#0.##");
        rating.setText("Rating: " + decimalFormat.format((item.getRating() * 2)) + "/10");
        visited.setText("Visited: " + item.getVisitedString());

        return listItem;
    }
}