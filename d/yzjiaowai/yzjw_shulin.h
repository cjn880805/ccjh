//yzjw_shulin.h



//Sample for room:  ��������
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_shulin);

virtual void create()			//Call it when Room Create

{

	set_name( "��������");

	add_npc("gaibang_kuai_huosan");
	add_npc("gaibang_qiu_wanjia");
	add_npc("gaibang_mo_bu");

	add_door("�������","�������","��������");
	add_door("����ɽ·2","����ɽ·2","��������");
	add_door("����ɽ·1","����ɽ·1","��������");
	add_door("��������5","��������5","��������");

};





ROOM_END;
