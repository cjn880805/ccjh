//suti1.h

//Sample for room: �����յ�1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_suti1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����յ�1");
	
	add_npc("pub_liumang");
	add_npc("pub_liumang");
	add_npc("pub_liumangtou");               //add by zdn 2001-07-14

	add_door("������ʯ���6", "������ʯ���6", "�����յ�1");
	add_door("�����յ�2", "�����յ�2", "�����յ�1");

	set("long"," �յ���ʫ���ն��������ֿ�������ʱ�ú���Ͳ����ɵġ��ն�������ʫ�������£�������Ǯ���غ��ˣ����ʿŮ�����ᡣ���ź���캺�ϣ���ɽʼ������ͨ��������ʮ�����ɣ�����ϯ����̿ա����������Ǵ�����ϱ��ǿ���š���������յ������ɱ����ϵĵ�һ������һ�����������ŵ���һ����������");

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
