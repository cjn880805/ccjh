//yuzhu.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_yuzhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("pub_youke");    // add by zdn 2001-07-13

	set("monster_chance", 50);

	add_door("������Ʒ�", "������Ʒ�", "����������");
	add_door("�������Ʒ�", "�������Ʒ�", "����������");

    set("long","���Ʒ����ϣ��з����ͦ�㣬���ͻ��������������´к��һˮ���������ߣ�ע����أ����ǹż����صġ�����Ȫ���ˡ�" );
    
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
