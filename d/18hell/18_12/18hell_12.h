//18hell_12.h
//ʮ�˵����ڰ˲���������BOSS����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_12);

virtual void create()			//Call it when Room Create
{
	set_name("��������");
	
	add_npc("chongtian");
	add_npc("diyu_shizhe12");

};

virtual int do_look(CChar * me)
{
	say("�Ҳ�����Χ�ǣ�Χ������ʯ����ʯ����ľ����ʯ����ľ�ʴ������ܡ�������ľ���ȡ�����ʯ������һ�޵�����������ͷ�����͸��񣬹��̵��������������ս��������ˡ�", me);
	say("�����Ǿ��������������ˣ��е�����������������̣������߶���������������������ȼ�ϣ�����������ǿ��Ѻ�������ߵ�����������������һ�ߴ���Ӳ�����ɡ�", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
