package com.jza.trains.utils;

public enum MessageStatus {
    SUCCESS(0),
    WARNING(1),
    ERROR(-1);

    Integer status;

    MessageStatus(Integer status) {
        this.status = status;
    }
}
