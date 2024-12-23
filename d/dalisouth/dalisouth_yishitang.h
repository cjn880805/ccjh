//yishitang.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDaLisouth_yishitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_zuzhang");
	add_npc("pub_shouling");      //add by zdn 2001-07-20
	
	add_door("������ϴ���¥", "������ϴ���¥", "�������������");
	add_door("������ϼ�����", "������ϼ�����", "�������������");

	set("long", "������¥���в������Ჿ�������ã����г��Ϸ�Ҫ�ձ��ڴ˾������ڴ��£�Ҳ�ڴ˽Ӵ������ͣ�����������ٸ�������ʹ�ߡ������Ա����ͼ�ڱڻ�������Ƥëװ���ıڡ�" );
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
