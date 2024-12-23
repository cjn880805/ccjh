//zhongfengsi.h

//Sample for room:  �����з���
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_zhongfengsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����з���");

	add_npc("pub_guest");
	add_npc("emei_youngwoman"); 
	add_npc("emei_puren");          //add by zdn 2001-07-20
				
	add_door("������ˮ��", "������ˮ��", "�����з���");
	add_door("����������", "����������", "�����з���");

	set("long","�з����ڰ��Ʒ��£�ʼ���ڽ�����ԭΪ���ۡ���˵���ڵĵ���ÿ�����������ն������ɽ��һ����������Ϊ�������ɡ������и�����������������ʦ��ɱ��������������ʿ��ʼ֪�ϵ����м����ѣ���Ը���ŷ�̣��Ӵ˸Ĺ�Ϊ�¡����������ɵ������󣬶�������ˮ�֡�");

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
