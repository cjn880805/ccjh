//fangheting.h

//Sample for room: ���ݷź�ͤ
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_fangheting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݷź�ͤ");
	
	add_npc("pub_playboy");        // add by zdn 2001-07-14

	add_door("���ݹ�ɽ", "���ݹ�ɽ", "���ݷź�ͤ");
	add_door("����ƽ������", "����ƽ������", "���ݷź�ͤ");

	set("long"," ͤ����������÷����һ����ĩ������÷��ʢ�ţ�εȻ�ɹۡ���ͤ��Ϊ�˼��������ʫ���ֺ;����������ᰮ÷��������Ӱ��бˮ��ǳ�����㸡���»ƻ衱��������ӽ÷���䡣�ݴ�˵��ʫ�˻�����һֻ��ȡ������������ÿ���Լ����ɢ����ǡ�п�������ʱ��ͯ�ӾͿ����źף�ʫ�˼��ף���ؼҽӿͣ��������С�÷�޺��ӡ��Ĺ��¡��������߱���ƽ�����¡����ϱ����ǹ�ɽ��");

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
