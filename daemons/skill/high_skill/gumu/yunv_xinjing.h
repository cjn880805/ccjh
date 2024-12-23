
// yunv_xinjing.h ��Ů�ľ�
//code by Fisho
//date : 2000-12-05

FORCE_BEGIN(CSyunv_xinjing);

virtual void create()
{
	CForce::create();

	set_name( "��Ů�ľ�");

	Magic_t * magic;

	magic = add_magic("heal", do_heal);
	magic->name = "������";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("powerup", do_powerup);
	magic->name = "������";
	magic->mp = 100;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("roar", do_roar);
	magic->name = "������";
	magic->mp = 800;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "force");
}

virtual int valid_learn(CChar * me)
{
	char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��")) 
		return notify_fail("�㲻�ǹ�Ĺ�ɵĵ���,����ѧϰ��Ů�ľ�?");
	
	if ( EQUALSTR(me->querystr("class"), "taoist") )
		return notify_fail(snprintf(msg, 255, "��Ů�ľ��ǹ�Ĺ�ɵľ�ѧ,%s������Ī��ĵ���,�Ͳ�����ѧ�˹��ˡ�",query_respect(me)));
	
	if (me->query_skill("yunv_xinfa", 1) < 10)
		return notify_fail("�����Ů�ķ���򻹲���,����������Ů�ľ���");
	
	if ( me->query_skill("bibo_shengong",1)
		|| me->query_skill("beiming_shengong",1)
		|| me->query_skill("biyun_xinfa",1)
		|| me->query_skill("xuedao_xinfa",1)
		|| me->query_skill("shenzhao_shengong",1)
		|| me->query_skill("tianlong_shengong",1)
		|| me->query_skill("bahuang_gong",1)
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong_dafa",1)
		|| me->query_skill("huntian_qigong",1)
		|| me->query_skill("jiuyang_shengong",1)
		|| me->query_skill("xiantian_gong",1)
		|| me->query_skill("wudu_xinfa",1)
		|| me->query_skill("hunyuan_yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong_shengong",1)
		|| me->query_skill("zixia_shengong",1)
		|| me->query_skill("shenlong_xinfa",1)
		|| me->query_skill("taiji_shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ů�ľ�����");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("��Ů�ľ�ֻ������̵������������ȡ�");
}

//perform 
static int do_heal(CChar * me, CContainer * ob)
{
	char msg[255];

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������");
	
	if (me->query_skill("yunv_xinjing", 1) < 20)
		return notify_fail("�����Ů�ľ���Ϊ��������");
	if( me->query("mp") < 50 ) 
		return notify_fail("�������������");
	
	if( me->query("eff_hp") < me->query("max_hp") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�");
	
	tell_object( me, "��ȫ����ɣ���������ʼ�˹����ˡ�" );
	tell_room( me->environment(),snprintf(msg,255,"%s�³�һ����Ѫ����ɫ�������ö��ˡ�" ,me->name()), me);
	me->receive_curing("hp", 10 + me->query_skill("force")/5 );
	me->add("mp", -50);
	me->set("mp_factor", 0l);
	me->start_busy(4);
	return 1;
}

static int do_powerup(CChar * me, CContainer * ob)
{
	int skill;
	
	if( me->query_skill("yunv_xinjing",1)< 10)
		return notify_fail("�����Ů�ľ���Ϊ����.");
	
	if( ob != me ) return notify_fail("��ֻ������Ů�ľ������Լ���ս������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( me->query("mp") < 100)
		return notify_fail("�����������!");
	if( me->querymap_temp("powerup") ) return notify_fail("���Ѿ����˹����ˡ�");
	
	skill = me->query_skill("force");
	
	me->add("mp", -100);
	me->receive_damage("hp", 0);
	
	message_vision("$N΢΢����ͷ�س�����Ǳ��Ĭ����Ů�ľ����μ��ľ��ܾ���΢һ̧ͷ����͸����Į��Ŀ�������ڳ��������ˣ�����û��ע�⵽$N������΢��ı仯��" , me);
	
	start_powerup(me, skill, skill/3, skill/3, "��������ϣ��������ջص����������������¶�������˵�΢Ц��");
	
	if( me->is_fighting() ) me->start_busy(3);
	
	return 1;
	
}

static int do_roar(CChar * me, CContainer * ob)
{
	int skill;
	
	if((me->environment())->query("no_fight"))
		return notify_fail("�����ֹս�����޷����ڹ����ˣ�");
	if( me->query("mp") < 800 )
		return notify_fail("�������������");

	if(DIFFERSTR(me->querystr("family/family_name"), "��Ĺ��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	skill = me->query_skill("force");
	
	me->add("mp", -500);
	me->receive_damage("hp", 10);
	
	me->start_busy(5);
	message_vision("$N�س���������һ����ȻһЦ��$N�������䣬�����˶�Ϊ֮һ��,��ʱȫ��������Ȼ��" , me);
	DTItemList search;
	POSITION p;
	CContainer * obj = NULL;
	CChar * who = NULL;
	
	CopyList(&search, (me->environment())->Get_ItemList());
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me )
			continue;
		
		who = (CChar *)obj;

		if( skill/2 + random(skill/2) < who->query("con") * 2  )
			continue;
		
			
		who->set_killer(me);
		me->set_killer(who);
		
		int damage = skill - (obj->query("max_mp") / 10);
		if( damage > 0 )
		{
			who->receive_damage("hp", damage * 2, me );
			if( who->query("mp") < skill * 2 )
				who->receive_wound("hp", damage, me);
			tell_object(who, "��ֻ������ǰһƬģ�����������ƺ�����������Ů�ڶ��������Ц,�����ɾ���");
		}
	}

	if(who && !who->query("no_huan"))
		who->fight_ob(me);	//�����������˶�kill���ˡ�

	return 1;
}

FORCE_END;
