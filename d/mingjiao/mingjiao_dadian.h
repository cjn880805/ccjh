//dadian.h



//Sample for room: 明教大殿

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_dadian);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "明教大殿");

	add_npc("pub_wushi");
	add_npc("pub_wushi");
	add_npc("pub_wushi");
	add_npc("pub_wushi");

	add_npc("mingjiao_zhangwuji");
	add_npc("mingjiao_yangxiao");
	add_npc("mingjiao_fanyao");
	add_npc("mingjiao_yintianzheng");
	add_npc("mingjiao_xiexun");
	add_npc("mingjiao_weiyixiao");
	add_npc("mingjiao_diana");

	add_door("明教广场", "明教广场", "明教大殿");

	set("long", "走进这里，突感一阵肃穆之意，大殿中十分空旷，殿顶高悬八盏金灯，两旁是精壮佩剑武士剑气森严逼人。正中设一宝座，前有一雕花檀木案，案头供明教圣火令(ling)六枚。宝座后立有一扇玉屏，屏中所画正是明教圣火图，烈焰直逼日月。宝座上端坐一人，着布衣而显高贵，含笑不怒而自威，正是明教教主张无忌。");
	
	set_temp("tieling",8);
	set_temp("lin_count",6);
	set_temp("shiwang_count",1);
	set_temp("zuoshi_count",1);
	set_temp("fuwang_count",10);
	set_temp("longwang_count",10);
	set_temp("youshi_count",8);
	set_temp("yingwang_count",8);

};





ROOM_END;




