//baiyun.h

//Sample for room: ���Ʒ�
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_baiyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ʒ�");

	add_npc("pub3_huangyishizhe");    // add by zdn 2001-07-13
	add_npc("guanwai_tengyilei");        //add by zdn 2001-07-20

	set("monster_chance", 50);

	add_door("����¹����", "����¹����", "������Ʒ�");
	add_door("�����ͷɽ���1", "�����ͷɽ���1", "������Ʒ�");
	add_door("����������", "����������", "������Ʒ�");

	set("long","���Ʒ������֮����¹����֮�ϣ�Ϊ����ɽ���塣ɽ��Բ���ߴ�����ض�������Ρ����磬��һ�ڱ���ֱ�����졣������ã����ʮ�����¶��Ω���˷峣���������ƣ����ղ�ɢ�������С����չ������׹ˣ���ɽ���ɰ��Ʒ⡱��������ٴ˷壬����ƮƮ����֮�С�" );
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
