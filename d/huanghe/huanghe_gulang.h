//gulang.h
//Sample for room: �ƺӹ���
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_gulang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӹ���");
	//add npcs into the room
	add_npc("pub_daoke");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("�ƺ�ѧ��", "�ƺ�ѧ��", "�ƺӹ���");
	add_door("�ƺ�ɳ��·", "�ƺ�ɳ��·", "�ƺӹ���");
	add_door("�ƺ�������", "�ƺ�������", "�ƺӹ���");
	add_door("�ƺӴ��", "�ƺӴ��", "�ƺӹ���");
	add_door("�ƺ�Ƥ��ҩ�ĵ�", "�ƺ�Ƥ��ҩ�ĵ�", "�ƺӹ���");
	set("long","���˳ǽ������ܣ��������䣬�������ں����������ˡ�����������������ëƤ��ɢ�أ������������Ƥ����һ�����żҿڣ���һ�������ǹ����ˣ����˹�����������ʮ������ˮ�Ӽ������ݡ�");

};

CHANGAN_END;
