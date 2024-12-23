// tiyunzong.c ������

FORCE_BEGIN(CStiyunzong);

virtual void create()
{
	set_name( "������");
	
	Magic_t * magic;

	magic = add_magic("zong", do_zong);
	magic->name = "������";
	magic->mp = 350;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
			{"ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�"},
			{"$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�"},
			{"$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�"}
	};

	return action[random(3)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("���ʦ����ʱû��ָ�����书����");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("����ʱ�޷�ָ������µ��书����");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ������������ݡ�");
	me->receive_damage("hp", 30);
	return 1;
}

static int do_zong(CChar * me, CContainer * ob)
{
	if(!me->is_fighting() )
		return notify_fail("\n�������ݡ�ֻ����ս����ʹ�á�");
	
	if(me->query_skill("tiyunzong",1) < 200 )
		return notify_fail("\n��������ݲ�����죬����ʹ�á������ݡ���");
	
	if(me->query_skill("taiji_shengong",1) < 120 )
		return notify_fail("\n���̫���񹦵ȼ�����������ʹ�á������ݡ���");  
	
	if(me->query_dex() < 28 )
		return notify_fail("\n�����̫�ͣ�����ʹ�á������ݡ���");
	
	if(me->query_skill("dodge",1) < 200 )
        return notify_fail("\n��Ļ����Ṧ̫����屿׾������ʹ�á������ݡ���");
	
	if(me->query("mp") < 400 )
		return notify_fail("\n�������̫���ˣ��޷�ʹ�ó��������ݡ���");   
	
	if (DIFFERSTR(me->query_skill_mapped("dodge"), "tiyunzong"))
		return notify_fail("\n�����ڼ������Ṧ�޷�ʹ�á������ݡ�������");  
	
	if( me->query_temp("zong"))
		return notify_fail("\n������ʹ�������ݵ���������������ݡ���");

	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") )
		return notify_fail("\n����Ȼ��������������ݡ���һ�У�����ȴ���������䵱��ʱ����ϳ��ˡ�\n");
	
	message_vision( "\n$HIW$NͻȻ����һ������һ̧���͵İθ����ɣ����Ƹվ���˫�������߳����������������������������������£�", me); 

	int improve =me->query("dex") * 5;
	me->add_temp("apply/dodge", improve);
	me->set_temp("zong",1);  
	me->add("mp", -(350-me->query_skill("tiyunzong",1)/10));
	me->UpdateMe();

	me->call_out(remove_effect, me->query_skill("tiyunzong") * 2/3,improve);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
    char msg[255];
	CChar * me = (CChar *)ob;  
	int improve=(int)param1;
	me->add_temp("apply/dodge", - improve);
	me->UpdateMe();
	me->delete_temp("zong");
	tell_object(me, "\n$HIR��ɢȥ�������۵������������������������������У��������ġ�\n");
	tell_room(me->environment(), snprintf(msg, 255,"\n$HIW%sȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n" ,me->name()));
}

SKILL_END;
