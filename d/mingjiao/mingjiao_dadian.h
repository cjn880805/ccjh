//dadian.h



//Sample for room: ���̴��

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_dadian);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "���̴��");

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

	add_door("���̹㳡", "���̹㳡", "���̴��");

	set("long", "�߽����ͻ��һ������֮�⣬�����ʮ�ֿտ����������յ��ƣ������Ǿ�׳�彣��ʿ����ɭ�ϱ��ˡ�������һ������ǰ��һ��̴ľ������ͷ������ʥ����(ling)��ö������������һ������������������������ʥ��ͼ������ֱ�����¡������϶���һ�ˣ��Ų��¶��Ը߹󣬺�Ц��ŭ���������������̽������޼ɡ�");
	
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




