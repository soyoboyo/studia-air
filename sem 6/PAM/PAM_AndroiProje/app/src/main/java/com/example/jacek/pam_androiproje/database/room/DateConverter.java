package com.example.jacek.pam_androiproje.database.room;

import android.arch.persistence.room.TypeConverter;

import java.util.Date;

public class DateConverter {

    @TypeConverter
    public static Date toDate(Long timestamp) { return timestamp == null ? null : new Date(timestamp); }

    @TypeConverter
    public static long toTimestamp(Date date) {
        return date == null ? null : date.getTime();
    }
}