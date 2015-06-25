#!/bin/sh

source /etc/tizen-platform.conf

if [ ! -d $TZ_SYS_DB ]
then
	mkdir $TZ_SYS_DB
fi

if [ ! -f $TZ_SYS_DB/.notification.db ]
then
	sqlite3 $TZ_SYS_DB/.notification.db 'PRAGMA journal_mode = PERSIST;
		create 	table if not exists noti_list (
			type INTEGER NOT NULL,
			layout INTEGER NOT NULL default 0,
			caller_pkgname TEXT NOT NULL,
			launch_pkgname TEXT,
			image_path TEXT,
			group_id INTEGER default 0,
			internal_group_id INTEGER default 0,
			priv_id INTERGER NOT NULL,
			title_key TEXT,
			b_text TEXT,
			b_key TEXT,
			tag TEXT,
			b_format_args TEXT,
			num_format_args INTEGER default 0,
			text_domain TEXT,
			text_dir TEXT,
			time INTEGER default 0,  
			insert_time INTEGER default 0,
			args TEXT,
			group_args TEXT,
			b_execute_option TEXT,
			b_service_responding TEXT,
			b_service_single_launch TEXT,
			b_service_multi_launch TEXT,
			b_event_handler_click_on_button_1 TEXT,
			b_event_handler_click_on_button_2 TEXT,
			b_event_handler_click_on_button_3 TEXT,
			b_event_handler_click_on_button_4 TEXT,
			b_event_handler_click_on_button_5 TEXT,
			b_event_handler_click_on_button_6 TEXT,
			b_event_handler_click_on_icon TEXT,
			b_event_handler_click_on_thumbnail TEXT,
			sound_type INTEGER default 0,
			sound_path TEXT,
			vibration_type INTEGER default 0,
			vibration_path TEXT,
			led_operation INTEGER default 0,
			led_argb INTEGER default 0,
			led_on_ms INTEGER default -1,
			led_off_ms INTEGER default -1,
			flags_for_property INTEGER default 0,
			flag_simmode INTEGER default 0,
			display_applist INTEGER,
			progress_size DOUBLE default 0,
			progress_percentage DOUBLE default 0,
			rowid INTEGER PRIMARY KEY AUTOINCREMENT,
			UNIQUE (caller_pkgname, priv_id)  
		);
		create table if not exists noti_group_data (
			caller_pkgname TEXT NOT NULL,
			group_id INTEGER default 0,
			badge INTEGER default 0,
			title TEXT,
			content TEXT,
			loc_title TEXT,
			loc_content TEXT,
			count_display_title INTEGER,
			count_display_content INTEGER,
			rowid INTEGER PRIMARY KEY AUTOINCREMENT,
			UNIQUE (caller_pkgname, group_id)
		);
		create 	table if not exists ongoing_list (
			caller_pkgname TEXT NOT NULL,
			launch_pkgname TEXT,
			icon_path TEXT,
			group_id INTEGER default 0,
			internal_group_id INTEGER default 0,
			priv_id INTERGER NOT NULL,
			title TEXT,
			content TEXT,
			default_content TEXT,
			loc_title TEXT,
			loc_content TEXT,
			loc_default_content TEXT,
			text_domain TEXT,
			text_dir TEXT,
			args TEXT,
			group_args TEXT,
			flag INTEGER default 0,
			progress_size DOUBLE default 0,
			progress_percentage DOUBLE default 0,
			rowid INTEGER PRIMARY KEY AUTOINCREMENT,
			UNIQUE (caller_pkgname, priv_id)
		);
		CREATE TABLE IF NOT EXISTS notification_setting ( 
			priv_id INTEGER PRIMARY KEY AUTOINCREMENT,
			package_name TEXT NOT NULL,
			allow_to_notify INTEGER DEFAULT 1,
			do_not_disturb_except INTEGER DEFAULT 0,
			visibility_class INTEGER DEFAULT 0,
			UNIQUE (priv_id, package_name)
		);
		CREATE TABLE IF NOT EXISTS notification_system_setting ( 
			priv_id INTERGER PRIMARY KEY,
			do_not_disturb INTEGER DEFAULT 0,
			visibility_class INTEGER DEFAULT 0,
			UNIQUE (priv_id)
		);

		INSERT INTO notification_system_setting (priv_id, do_not_disturb, visibility_class) VALUES (0, 0, 0);

		CREATE UNIQUE INDEX package_name_idx1 ON notification_setting (package_name);
	'
fi

users_gid=$(getent group $TZ_SYS_USER_GROUP | cut -f3 -d':')

chown :$TZ_SYS_USER_GROUP $TZ_SYS_DB/.notification.db
chown :$TZ_SYS_USER_GROUP $TZ_SYS_DB/.notification.db-journal
chmod 640 $TZ_SYS_DB/.notification.db
chmod 640 $TZ_SYS_DB/.notification.db-journal
chsmack -a 'User' $TZ_SYS_DB/.notification.db*
SMACK_OPTION="-s system::vconf_misc"
vconftool set -t string memory/private/libstatus/message "" -i -g $users_gid -f  $SMACK_OPTION
