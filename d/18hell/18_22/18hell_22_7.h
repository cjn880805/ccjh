//18hell_22.h
//ʮ�˵�����ʮ�˲㰢�ǵ�����7����

ROOM_BEGIN(CR18hell_22_7);

virtual void create()			//Call it when Room Create
{
	set_name("���ǵ���");
	
	add_npc("diyu_shizhe22");

};

virtual int do_look(CChar * me)
{
	say("������ͬ��״�����š���������ǽ����ͤ��¶��Զ�����Ҳ��У�������������ʯ�����϶��£�ʯ�������Ź���վ�ں��������������ڿ�����", me);
	say("���������ͺ���Ÿ��ִ�С���������������ܲ�������һ���ͽ����������룬ֱ���������������˱����ڽ����£�һ�����ſ�Ѫ����ҧ�����˲��ھ����ϣ����۲�ͣ���������˵Ķ���", me);
	say("�����ɳ�����������˱����俴Ѻ�����ڲ�ͣ�ر�ɳ���Աߣ�����������׷�Ϻͱ޴��ﷸ��ǿ���ﷸ����ϵ��ܿࡣ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;