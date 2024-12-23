//yueying_wubu.h ��Ӱ�貽

SKILL_BEGIN(CSyueying_wubu);

virtual void create()
{
	set_name( "��Ӱ�貽");

	Magic_t * magic;
	
	magic = add_magic("jianwu", do_jianwu);
	magic->name = "��֮��";
	magic->mp = 120;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("huawu", do_huawu);
	magic->name = "��֮��";
	magic->mp = 350;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[9][80]={	
		{"$n����һ�Σ�����һŤ��һ�С��Ǻ����𡹣����ض���"},
		{"$nһ�С��辡�һ��ȵ׷硹��$Nֻ����ǰһ����������$n����Ӱ��"},
		{"$nһ�С�ɨ�����Ʒ粻����������΢�Σ��о����յرܿ���$N��һ�С�"},
		{"ֻ��$n�������һ����һ�С�����º�Ӱ�����󵴶�������һ�ԡ�"},
		{"$nһ�С�����Ū��Ӱ�������䷭�ɣ����$N��һ�С�"},
		{"ȴ��$n�����꽭��һ�طɡ����������һ�����ۣ��������ۡ�"},
		{"����$nһ������ˮ�仨��ȥҲ��������һ�ã�$N��һ�����˸��ա�"},
		{"ֻ��$nһ�С����ִ���ˮ�޺ۡ����������Σ����������ת���˳����ɿ��⡣"},
		{"$nϢ���������������һ�С���������Ӱ�ڲ���������ƮȻ����"},
	};

	return dodge_msg[random(9)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 45 )
		return notify_fail("�������̫���ˣ���������Ӱ�貽��");

	me->receive_damage("hp", 35);
	return 1;
}

//��֮��
static int do_jianwu(CChar * me, CContainer * ob)
{
	if(!me->is_fighting() )
		return notify_fail("\n����֮�衹ֻ����ս����ʹ�á�");
	
	if(me->query_skill("yueying_wubu",1) < 200 )
		return notify_fail("\n�����Ӱ�貽������죬����ʹ�á���֮�衹��");
	
	if(me->query_skill("bahuang_gong",1) < 120 )
		return notify_fail("\n��İ˻�����Ψ�Ҷ��𹦵ȼ�����������ʹ�á���֮�衹��");  

	if(me->query_dex() < 26 )
		return notify_fail("\n�����̫�ͣ�����ʹ�á���֮�衹��");
	
	if(me->query_skill("dodge",1) < 200 )
        return notify_fail("\n��Ļ����Ṧ̫����屿׾������ʹ�á���֮�衹��");

	if(me->query_skill("sword",1) < 120 )
		return notify_fail("\n��Ľ���̫��޷���ᵽ����֮�衹��Ҫ����");  
	
	if(me->query("mp") < 120 )
		return notify_fail("\n�������̫���ˣ��޷�ʹ�ó�����֮�衹��");   
	
	if (DIFFERSTR(me->query_skill_mapped("dodge"), "yueying_wubu"))
		return notify_fail("\n�����ڼ������Ṧ�޷�ʹ�á���֮�衹������");  

	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("\n$HIR����ͼ���š���֮�衹�Ľ����趯���������ǿ����Լ�������������ɵ�ֹס������"); 

	if( me->query_temp("wu"))
		return notify_fail("\n�������潣���裡");

	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") )
		return notify_fail("\n����ϡ�ǵ�����ѧ������֮�衹��һ�У����Ǽ��ʱ��̫���Ѿ��޷�ȫ�������ˡ�\n");
	
	message_vision( "\n$HIW$N��һ�����������Ṧ���ν����衣ֻ��$N�㲻մ�أ����н�Խ��Խ�죬�𽥻���һ�Ű������ù�����\n", me); 

	int skill_dodge = me->query_skill("dodge"); 
	int skill_sword=me->query_skill("sword");
	int attack_amount=skill_sword*random(6)/10;
	int dodge_amount=skill_dodge*(5+random(6))/10; 
	me->add_temp("apply/attack", -attack_amount);  
	me->add_temp("apply/dodge",dodge_amount); 

	me->set_temp("wu",1);  
	me->add("mp", -100);
	me->UpdateMe();

	me->call_out(remove_effect, me->query_skill("yueying_wubu") * 2/3,attack_amount,dodge_amount);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;  
	int attack_amount=(int)param1;
	int dodge_amount=(int)param2;
	me->add_temp("apply/attack", attack_amount);  
	me->add_temp("apply/dodge",-dodge_amount); 
	me->UpdateMe();

	me->delete_temp("wu");
	message_vision("\n$HIW$N����������֧�����ò������Ų����Ż����С�\n",me);
}

//��֮��
static int do_huawu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	
	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || ! me->is_fighting(target))
		return notify_fail("\n����֮�衹ֻ����ս����ʹ�á�");

	if(target->is_busy() )
        return notify_fail("%sĿǰ���ܶ������ŵ������ɣ�", target->name());
	
	if(me->query_skill("yueying_wubu",1) < 220 )
		return notify_fail("\n�����Ӱ�貽������죬����ʹ�á���֮�衹��");
	
	if(me->query_skill("bahuang_gong",1) < 180 )
		return notify_fail("\n��İ˻�����Ψ�Ҷ��𹦵ȼ�����������ʹ�á���֮�衹��");  

	if(me->query_dex() < 28 )
		return notify_fail("\n�����̫�ͣ�����ʹ�á���֮�衹��");
	
	if(me->query_skill("dodge",1) < 220 )
        return notify_fail("\n��Ļ����Ṧ̫����屿׾������ʹ�á���֮�衹��");
	
	if(me->query("mp") < 350 )
		return notify_fail("\n�������̫���ˣ��޷�ʹ�ó�����֮�衹��");   
	
	if (DIFFERSTR(me->query_skill_mapped("dodge"), "yueying_wubu"))
		return notify_fail("\n�����ڼ������Ṧ�޷�ʹ�á���֮�衹������");  

	if (DIFFERSTR(me->querystr("gender"), "Ů��"))
		return notify_fail("\n$HIR����ͼ���š���֮�衹�Ľ����趯���������ǿ����Լ�������������ɵ�ֹס������"); 
	
	if(DIFFERSTR(me->querystr("family/family_name"), "���չ�") )
		return notify_fail("\n����ϡ�ǵ�����ѧ������֮�衹��һ�У����Ǽ��ʱ��̫���Ѿ��޷�ȫ�������ˡ�\n");
	
	message_vision( "\n$HIY$N��ȻһЦ����������������$n����������$n����һ�㡣\n$N���������ת�ţ���ʱ������һ��������Բ����$N�����޹ǵĽ������һ��������ա�", me,target); 

	int lv = me->query_skill("yueying_wubu",1)/80;
	lv=lv+me->query("per")/15;

	if(random(me->query("combat_exp")) > target->query("combat_exp")/2)
	{
		message_vision( "$HIR���$n��$NΧ��ˮй��ͨ��", me,target); 
		target->start_busy(lv);
		me->add("mp", -300);
		me->start_busy(1);
	} 
	else
	{
		message_vision( "$HIG$nֻ��һ���������������ˡ�", me,target); 
		me->add("mp", -150);
		me->start_busy(1);
	}
	
	me->UpdateMe();

	return 1;
}

SKILL_END;

