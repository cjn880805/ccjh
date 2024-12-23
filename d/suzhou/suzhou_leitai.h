//leitai.h

//Sample for room: ��̨ǰ�㳡
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_leitai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��̨ǰ�㳡");
	
	add_npc("pub_daoke");
	add_npc("pub_jianke");          //add by zdn 2001-07-16
	add_npc("pub_zhongbuliang");
	add_npc("pub_shuiyunyan");
	add_npc("pub_zhuoyihang");


	add_door("������", "������", "������̨ǰ�㳡");

	set("long", "������������̨ǰ���һ�����͹㳡���������������̨�ϱ��䣬��������ɽ�˺��������Ҳ���������֣���ô����������̨���Ա��԰ɡ�" );
 	set("outdoors", "suzhou");
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;




