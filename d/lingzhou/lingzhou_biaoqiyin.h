//biaoqiyin.h

//Sample for room: ����Ӫ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_biaoqiyin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ӫ");

	//add npcs into the room
	add_npc("pub_xixiabing");/////////////////////////

	add_door("������", "������", "��������Ӫ");

	set("long", "�����ǻ��ҽ�������פ�أ������ݳ�����������Ӫռ������Ӵ󣬱�����Ӫ����������СУ������������ų�ǽ��һ����ǣ��ж�Ӫ�ź���Ӫ��ͨ��ʹ��ʹ�֡�����Ӫ�ľ�ʿ�������ľ���ǧ����ѡ����ʿ��ƽʱ����ʳ���Χ�ľ��䣬���ϳ�Ѳʱ�����𿪵�����������սʱ����һ֧��������");  

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
