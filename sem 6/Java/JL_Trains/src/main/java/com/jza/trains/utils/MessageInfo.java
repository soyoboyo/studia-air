package com.jza.trains.utils;

import lombok.*;

@Getter
@Setter
@ToString
@Builder
@EqualsAndHashCode
public class MessageInfo {
	private MessageStatus status;
	private String message;
	private Object object;
}
