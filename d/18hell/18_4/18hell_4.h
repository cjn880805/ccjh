//18hell_4.h
//ʮ�˵�������κ���BOSS����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_4);

virtual void create()			//Call it when Room Create
{
	set_name("���Źؿ�");
	set("long", "һ����ʽ¥ͤ���ĽǷ��ܡ���ڵ�ɽ�ſ�����������ã��Ѫ���ĺ����ϣ����ź��˵ġ����Źء��������֣�����עĿ���ز������Σ�ȸѻ���룬�������£�������ɭ�ֲ�֮�С�");
	
	add_npc("yijian_feixian");
	add_npc("diyu_shizhe4");

};

ROOM_END;
