//18hell_3.h
//ʮ�˵�����ڹ��Ź�BOSS����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_3);

virtual void create()			//Call it when Room Create
{
	set_name( "�κ���ͷ");
	set("long", "������ͨ��ʮ�˵����ġ��κ��š����������е�ʯ���ţ�������ƽ�أ���С��������ȫ��ͬ��ÿ�ſ���ĳ������໤�Ե�ʯ���������Գʻ��Σ�����ʯ���������˸�������̤�������¿�һ���γأ��ص׼��űھ�Ϊ��ʯǶ��������Ѫ����������������η������ȷ����档");
	
	add_npc("wanbaolou_sisi");
	add_npc("diyu_shizhe3");

};

ROOM_END;
