//huangtu.h

//Sample for room: �ƺӻ�����ԭ
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huangtu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӻ�����ԭ");
	
	add_npc("monster_8k");
	add_npc("monster_6k");            // add by zdn 200-07-14
	add_npc("pub_lianjin");

	add_door("��ľ�����Ŷɿ�", "��ľ�����Ŷɿ�", "�ƺӻ�����ԭ");
	add_door("�ƺӺ���", "�ƺӺ���", "�ƺӻ�����ԭ");

	set("long","�ƺ���һ�����н�������ԭ�п���������СϪ���д�����ɳ����ƺӣ��γ�ǧ�����֡�����֮���һ���ƽ�ؽ���̨ܫ���ƺ����ɹŸ�ԭ�ϱ������ʣ���̫��ɽ������������תͷ���£��γɽ��µķֽ硣");
    

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"hetao",
		"southwest" : __DIR__"huanghe_2",
	]));
********************************************/
};


CHANGAN_END;
