//haigang.h

//Sample for room: ������
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_haigang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_chuanfu");
	add_npc("pub_flowerg");
	add_npc("mingjiao_changjinpeng");
	add_npc("pub_shenjiqiu");
	add_npc("pub_zhangzhongding");
	
	add_door("���������9", "���������9", "����������");
	add_door("�����̺�̲", "�����̺�̲", "����������");
	
	set("long", "������Ǵ�֮�����˻��Ĵ��Ž�ʯ����������������������һȺȺ��Ÿ��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻����������Ҵ�(chuan)���������ż����������ˣ��˴��ɶɹ��󺣵��ﺣ����һ�ˡ���������Ǿ��Ǳ����ˣ�������һ���޼ʵĴ󺣡�" );


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
