//jieduwan.h �ⶾ������

FOOD_BEGIN(CIjieduwan);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("�ⶾ������", "jiedu wan");
	
	set_weight(20);
	
	set("long","����һ���ⶾ������,�ɽ�ٶ���");
	set("value", 1);      
	set("unit", "��");
	
};

virtual int do_use(CChar * me, CContainer * ob)
{
	CChar * npc = NULL;
	
	if(ob && ob->is_character())
		npc = (CChar *)ob;
	
	if(! npc || npc == me || userp(npc))
		return notify_fail("��Ҫ��˭ʹ�ã�");
	
	if (me->is_fighting())
		return notify_fail("�����޷�ʹ�ýⶾ�����裡");
	
	if(EQUALSTR(npc->querystr("name"), "ʯ��¶") && EQUALSTR(npc->querystr("id"), "shi ganlu")  && me->query_temp("xy/renwu1_41"))
	{
		//npc->enable_player();
		//npc->delete_temp("apply/name");
		//npc->UpdateMe();
		//npc->del("����");
		me->set_temp("xy/renwu1_42",1);//��ʯ��¶�ⶾ
		tell_object(me,"\n��С�����ȵ�ιʯ��¶�����˽ⶾ�����衣");
		tell_object(me,"ֻ��ʯ��¶���ϵ����������ˣ�ʯ��¶����Ӵ��һ���������������˹�����\n");
		
		destruct(this);
		me->start_busy(1);
		return 1;
	}
	return 0;
}
    
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp