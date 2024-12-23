//hcaeast.h

//Sample for room:  ���һ����ֶ����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaeast);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���һ����ֶ����");

	add_npc("emei_wenhui");
	add_npc("emei_he");

	add_door("���һ���������", "���һ���������", "���һ����ֶ����");

	set("long","�����ǽ𶥻����ֶ����ǽӴ���ͼ������ĵط������ڰ��ż������ӣ�����Χ���������ӡ�ǽ�����ż����ֻ���ǽ��һ����ܣ����ϰ������顣�м�λ���������Ʒ����������ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ����Ĺ�������һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰæ���д����ˡ�");
 
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
