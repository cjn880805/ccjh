//biguanshi.h
//Sample for room: ��ң�ȱչ���

ROOM_BEGIN(CRXiaoYao_biguanshi);

virtual void create()
{
	set_name( "�չ���");

	set("no_autosave",1);

	add_npc("xy_tielao1");

	add_door("����Ǿ���7", "��ң�ȴ���Ǿ���7", "��ң�ȱչ���");
};


ROOM_END;

