//wannianan.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_wannianan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("pub_nigu1");          //add by zdn 2001-07-14
				
	add_door("���Ұ�����", "���Ұ�����", "����������");
	add_door("����ʮ����1", "����ʮ����1", "����������");

	set("long","�����ֽ���һ��ͻ���ɽ���ϣ���Χ��ľɭɭ����Ȫ���ȣ��в��޿��������޿�����ɫ�ǳ����ˡ��ɴ����Ϲ�ʮ���̿ɴﻪ�϶�����������������");
    

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
