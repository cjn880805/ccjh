// mtg.h ħ�������� NPCר��
// Teapot
// 2001-03-09

FORCE_BEGIN(CSmtg);

virtual void create()
{
	CForce::create();

	set_name( "ħ��������");

	Magic_t * magic;

	magic = add_magic("blindinglight", do_blindinglight);
	magic->name = "ѣ��һ��";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("dismantlingblow", do_dismantlingblow);
	magic->name = "��ɢ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("globalruin", do_globalruin);
	magic->name = "�������";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("disenchant", do_disenchant);
	magic->name = "����ħ��";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("spiritwave", do_spiritwave);
	magic->name = "֯����";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("skywave", do_skywave);
	magic->name = "֯����";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("hatewave", do_hatewave);
	magic->name = "֯����";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("ragewave", do_ragewave);
	magic->name = "֯ŭ��";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("mightwave", do_mightwave);
	magic->name = "֯����";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("sunscape", do_sunscape);
	magic->name = "����Ժ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("stormscape", do_stormscape);
	magic->name = "᰾�Ժ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("nightscape", do_nightscape);
	magic->name = "ҹ��Ժ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("thunderscape", do_thunderscape);
	magic->name = "�׾�Ժ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("thornscape", do_thornscape);
	magic->name = "����Ժ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("manalock", do_manalock);
	magic->name = "����������";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("manarecover", do_manarecover);
	magic->name = "�ع�";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("dominariajudgment", do_dominariajudgment);
	magic->name = "���������Ǵ�����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("lobotomy", do_lobotomy);
	magic->name = "��Ҷ�г�";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("washout", do_washout);
	magic->name = "��ˢ����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("repulse", do_repulse);
	magic->name = "����";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("parallaxtide", do_parallaxtide);
	magic->name = "ʱ�����˳�";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;


}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("����ֻ����ѧ�������������ȡ�");
}

static int do_parallaxtide(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * obj;
	obj=me->environment();


	if( me->query("mp") <= 50 || obj->querystr("name")=="�����Ϻ�" || !target)
		return notify_fail("Parallax Tide�޷�ʹ�á�");

	snprintf(msg ,255,"$N����������������һ����ɫ�Ĺ�â����%s��ֻ��%s�ڿ����ܽ���ˣ�",target->name(),target->name());
	message_vision(msg, me);

	target->move(load_room("�����Ϻ�"));

	message_vision("����ͻȻһ���𶯣�$N�����������֮�и��ֳ�����", target);
	target->start_busy(2);

	me->add("mp", -50);

	return 1;
}



static int do_repulse(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || target==me)	// User cannot be the target of this spell.
		return notify_fail("Repulse�޷�ʹ�á�");
	
	if( me->query("mp") <= 50 )
		return notify_fail("Repulse�޷�ʹ�á�");
	

	snprintf(msg ,255,"$N��������������������ⲻ�������ļһֻ��һ����ɫ�Ĺ�â����%s��%s����ʮ�ɿ��⣡",target->name(),target->name());
	message_vision(msg, me);

	CContainer * obj;
	obj=me->environment();
	CContainer * obj2;
	obj2=obj->environment();
	target->move(obj2);

	message_vision("$N����ս�������˳�����", target);
	target->start_busy(2);

	me->add("mp", -50);

	return 1;
}


static int do_washout(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || userp(target) )	// User cannot be the target of this spell.
		return notify_fail("Wash out�޷�ʹ�á�");
	
	if( me->query("mp") <= 50 )
		return notify_fail("��ķ�����������");
	
	DTItemList * list = target->Get_ItemList();
	CContainer * item;
	POSITION pos;
	
	snprintf(msg ,255,"$N����������������һ����ɫ�Ĺ�â����%s��ֻ��%s����һ�Σ�",target->name(),target->name());
	message_vision(msg, me);
	
	if(list->GetCount())
	{
		
		
		pos = list->GetHeadPosition();
		while(pos)
		{
			item = list->GetNext(pos);
			target->command(snprintf(msg, 255, "drop %ld", item->object_id()));
		}
	}
	
	message_vision("$N�뿪��Ϸ��", target);
	destruct(target);
	
	me->add("mp", -50);

	return 1;
}




static int do_lobotomy(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target /*|| !me->is_fighting(target)*/ )
		return notify_fail("Lobotomy�޷�ʹ�á�");
	
	if( me->query("mp") <= 50 )
		return notify_fail("��ķ�����������");
	
	
	
	
	DTItemList * list = target->Get_ItemList();
	CContainer * item;
	POSITION pos;
	
	if(list->GetCount())
	{
		
		snprintf(msg ,255,"$N����������������һ����ɫ�Ĺ�â����%s��%sһ���㱣�ֻ�������пյ����ģ�ʲôҲ���ǵã�",target->name(),target->name());
		message_vision(msg, me);
		
		pos = list->GetHeadPosition();
		while(pos)
		{
			item = list->GetNext(pos);
			target->command(snprintf(msg, 255, "drop %ld", item->object_id()));
		}
	}
	else
		return notify_fail("û��Lobotomy����ָ���ĺϷ�Ŀ�꣡");
	
	
	me->add("mp", -50);
	
	return 1;
}



static int do_dominariajudgment(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("Dominaria's Judgment�޷�ʹ�á�");
	
	if( me->query("mp") < 250 )
		return notify_fail("��ķ�����������");
	
	snprintf(msg ,255,"һ�ֲ԰�֮�����Ϸ����𣬶�����������ɫ�Ĺ����ҫ��$N��$N����һ�񣬷���ȫ��һ����");
	message_vision(msg, me);

	int i;
	i=me->query("mp");
	me->set("mp_factor",i);

	i=me->query("level");
	me->set("level",300);
	me->add_temp("apply/attack",30000000);

	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
	
	me->add_temp("apply/attack",-30000000);
	me->set("level",i);
	me->set("mp_factor",0l);
//	me->set("mp",0);

//	me->add("mp", -250);

	return 1;
}

static int do_sunscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("����Ժ�����޷�ʹ�á�");
	
	if( me->query("mp") < 50 )
		return notify_fail("��ķ�����������");
	
	snprintf(msg ,255,"ͻȻ$N��ͷ�ϵ���ӡ�����׹⣬ֻ��$N��ȵ��������˶���ͬ��Э��������ʤ����Զ���ή�٣�");
	message_vision(msg, me);
	snprintf(msg ,255,"$N�ƺ��ܵ��˼�����𶯣�");
	message_vision(msg, target);
	int i;
	i=target->query("repute");
	i=me->query("repute")-i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_stormscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("᰾�Ժ�����޷�ʹ�á�");
	
	if( me->query("mp") < 50 )
		return notify_fail("��ķ�����������");
	
	snprintf(msg ,255,"ͻȻ$N��ͷ�ϵ���ӡ�������⣬ֻ��$N��ȵ�����Ϣ�ɣ���ûӮҲû�䣬��ս��������ԣ������ǽ����ˣ�");
	message_vision(msg, me);
	snprintf(msg ,255,"$N�ƺ��ܵ��˼�����𶯣�");
	message_vision(msg, target);
	int i;
	i=target->query("mp");
	i=me->query("mp")-i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",1,me);
	target->add("mp",-i);
	target->receive_damage("hp",1,me);
	me->add("mp", -50);
	return 1;
}

static int do_nightscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("ҹ��Ժ�����޷�ʹ�á�");
	
	if( me->query("mp") < 50 )
		return notify_fail("��ķ�����������");
	
	snprintf(msg ,255,"ͻȻ$N��ͷ�ϵ���ӡ������â��ֻ��$N��ȵ������ǵĵ�������ζ����İ�Ϸ�����ˣ�");
	message_vision(msg, me);
	snprintf(msg ,255,"$N�ƺ��ܵ��˼�����𶯣�");
	message_vision(msg, target);
	int i;
	i=target->query("repute");
	i=me->query("repute")+i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_thunderscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("�׾�Ժ�����޷�ʹ�á�");
	
	if( me->query("mp") < 50 )
		return notify_fail("��ķ�����������");
	
	snprintf(msg ,255,"ͻȻ$N��ͷ�ϵ���ӡ������â��ֻ��$N��ȵ��������Ǿ�����ͨ�����ԣ�");
	message_vision(msg, me);
	snprintf(msg ,255,"$N�ƺ��ܵ��˼�����𶯣�");
	message_vision(msg, target);
	int i;
	i=target->query("hp");
	i=me->query("hp")-i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_thornscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("����Ժ�����޷�ʹ�á�");
	
	if( me->query("mp") < 50 )
		return notify_fail("��ķ�����������");
	
	snprintf(msg ,255,"ͻȻ$N��ͷ�ϵ���ӡ�����໪��ֻ��$N��ȵ����������룬���ܶ����ҵ�һ�У�����������������㹻��");
	message_vision(msg, me);
	snprintf(msg ,255,"$N�ƺ��ܵ��˼�����𶯣�");
	message_vision(msg, target);
	int i;
	i=target->query("mp");
	i=me->query("mp")+i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_mightwave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N����������ҵ������ᶨ��ľ��ġ���", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/str",20);
		target->call_out(do_removegreenspelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removegreenspelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/str",-20);
	message_vision("$N�����̹���ɢ�����е�֯������Ч�������ˡ�", me);
	return ;
}


static int do_ragewave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N����������ҵ����鼤�����ʤ������", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/dex",20);
		target->call_out(do_removeredspelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removeredspelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/dex",-20);
	message_vision("$N���Ϻ����ɢ�����е�֯ŭ����Ч�������ˡ�", me);
	return ;
}


static int do_hatewave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N����������ҵĳ����ǿ��ķ�ŭ����", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/damage",300);
		target->call_out(do_removeblackspelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removeblackspelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/damage",-300);
	message_vision("$N���Ϻڹ���ɢ�����е�֯������Ч�������ˡ�", me);
	return ;
}







static int do_skywave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N����������ҵ��ǻ۴�����������", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/dodge",1000);
		target->call_out(do_removebluespelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removebluespelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/dodge",-1000);
	message_vision("$N����������ɢ�����е�֯������Ч�������ˡ�", me);
	return ;
}



static int do_spiritwave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N����������ҵ�ϣ����Ϊ��Ķܡ���", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/armor",1000);
		target->call_out(do_removewhitespelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removewhitespelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/armor",-1000);
	message_vision("$N���ϰ׹���ɢ�����е�֯������Ч�������ˡ�", me);
	return ;
}


static int do_disenchant(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target /*|| !me->is_fighting(target)*/ )
		return notify_fail("Disenchant�޷�ʹ�á�");
	
	if( me->query("mp") <= 50 )
		return notify_fail("��ķ�����������");
	

		DTItemList * list = target->Get_ItemList();
		CContainer * item;
		POSITION pos;
		int flag;
	
		if(list->GetCount())
		{
									
		pos = list->GetHeadPosition();
			while(pos)
			{
				item = list->GetNext(pos);
				if (item->query("equipped") && item->query("apply/damage"))
				{
					flag=1;
					break;
				}	
			}
			if (!flag)
				return notify_fail("û��Disenchant����ָ���ĺϷ�Ŀ�꣡");
		}
		else
				return notify_fail("û��Disenchant����ָ���ĺϷ�Ŀ�꣡");
		if (!item->query("equipped") || !item->query("apply/damage"))
				return notify_fail("û��Disenchant����ָ���ĺϷ�Ŀ�꣡");

	snprintf(msg ,255,"$N����������������һ����ɫ�Ĺ�â������%s��ֻ��һ�����죬%s���е������Ѿ�ɢ�ѣ�",target->name(),target->name());
	message_vision(msg, me);
	item->set("no_sell",1);
	item->del("apply");
	item->set_name( snprintf(msg, 255, "��Disenchant�򻵵�%s", item->name()));	
	item->move(me->environment());
	
	me->add("mp", -50);

	return 1;
}


static int do_globalruin(CChar * me, CContainer * ob)
{
	CContainer * obj;
	obj=me->environment();
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");
	if (!obj->query("room_locked"))
		return notify_fail("Global Ruin�޷�ָ����ЧĿ�꣡");

	me->add("mp", -100);
	message_vision("$N���������дʵ������ҡ�����콵���꣬���皧��", me);
	message_vision("ֻ��һ����Ȼ���𣬷·�ʲô������һ�㣡", me);
	obj->set("room_locked",0l);

	return 1;

}

static int do_dismantlingblow(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target /*|| !me->is_fighting(target)*/ )
		return notify_fail("Dismantling Blow�޷�ʹ�á�");
	
	if( me->query("mp") <= 50 )
		return notify_fail("��ķ�����������");
	

		DTItemList * list = target->Get_ItemList();
		CContainer * item;
		POSITION pos;
		int flag;
	
		if(list->GetCount())
		{
									
		pos = list->GetHeadPosition();
			while(pos)
			{
				item = list->GetNext(pos);
				if (item->query("equipped") && item->query("apply/armor"))
				{
					flag=1;
					break;
				}	
			}
			if (!flag)
				return notify_fail("û��Dismantling Blow����ָ���ĺϷ�Ŀ�꣡");
		}
		else
				return notify_fail("û��Dismantling Blow����ָ���ĺϷ�Ŀ�꣡");
		if (!item->query("equipped") || !item->query("apply/armor"))
				return notify_fail("û��Dismantling Blow����ָ���ĺϷ�Ŀ�꣡");

	snprintf(msg ,255,"$N����������������һ����ɫ�Ĺ�â������%s��ֻ��һ�����죬%s���ϵĴ����Ѿ�ɢ�ѣ�",target->name(),target->name());
	message_vision(msg, me);
	
	item->del("apply");
	item->set("no_sell",1);
	item->set_name( snprintf(msg, 255, "��Dismantling Blow�򻵵�%s", item->name()));	
	item->move(me->environment());
	
	me->add("mp", -50);

	return 1;
}

static int do_blindinglight(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("��ķ������㣡");

	me->add("mp", -100);

	message_vision("$N���������дʵ�����ʹ������ֻ�ܴ������壬���ҵ���ֱȴ��͸����ģ�", me);


	//ѣ��һ�������С���ȫ�壡
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
//		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(! target->is_fighting(me)) continue;
		if(target==me) continue;
		
		target->start_busy(5);
		target->SendState();

//		msg="ֻ��ѣ��һ����$N����ǰһƬ��â��";
		message_vision("ֻ��ѣ��һ����$N����ǰһƬ��â��", target);
	}

//	me->start_busy(1+random(2));	// Cose 2W.
	return 1;
}

static int do_manalock(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
//	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("�����������޷�ʹ�á�");
	
//	if (! (weapon = me->query_weapon())
//		||  weapon->querystr("skill_type") != "sword")
//		return notify_fail("��ɽ��ػ�޷�ʹ�á�");
	
	if( me->query("mp") <= 1500 )
	{
		me->set("mp",0l);
		return notify_fail("��ķ�����������");
	}
	
	snprintf(msg ,255,"$N���������������ɵ���ɫ�Ĺ�â������%s��Χ����ס��%s��",target->name(),target->name());
	message_vision(msg, me);
	
	
	me->add("mp", -1500);
	me->start_busy(2);
	target->start_busy(2);

	me->call_out(do_kml, 1, target->object_id(), 1);	// Keep Manalock

	
	return 1;
	
}

static void do_kml(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	CChar * target = (CChar *)(me->environment())->Present(param1);
//	CContainer * weapon;
	char msg[255];


	if( !target || !me->is_fighting(target) )
		return ;
	
	if(! living(me))
		return ;

	if( me->query("mp") < 1500 )
	{
		tell_object(me,"��ķ���˥���ˡ�");
		snprintf(msg ,255,"����ɫ�Ĺ�â������ʧ�����ˡ�");
		target->start_busy(1);
		me->start_busy(3);
		me->set("mp",0l);
		message_vision(msg, me);
		return ;
	}

	me->add("mp",-1500);

	snprintf(msg ,255,"һ����ɫ�Ĺ�â��$N����������");
	message_vision(msg, target);

	me->start_busy(2);
	target->start_busy(2);

	me->call_out(do_kml, 1, target->object_id(), 1);	// Keep Manalock



}




static int do_manarecover(CChar * me, CContainer * ob)
{
	char msg[255];

	if(ob !=me)
		return notify_fail("��ֻ�ܶ��Լ�ʩչ�ع⡣");

	if( me->query("hp") <= 2000 )
		return notify_fail("�������������");
	
	snprintf(msg ,255,"$N�������������������ɵ���ɫ�Ĺ�â�������Լ���Χ��");
	message_vision(msg, me);
	
	me->add("hp", -2000);
	me->add("mp", 1500);

	me->call_out(do_kmr, 1, me->object_id(), 1);	// Keep Manalock
	return 1;
}

static void do_kmr(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
//	CChar * target = (CChar *)(me->environment())->Present(param1);
//	CContainer * weapon;
	char msg[255];


//	if( !target || !me->is_fighting(target) )
//		return ;
	
	if(! living(me))
		return ;

	if( me->query("hp") <= 2000 )
	{
		tell_object(me,"�������˥���ˡ�");
		snprintf(msg ,255,"����ɫ�Ĺ�â������ʧ�����ˣ�$N�������£�ˤ���ڵ��ϡ�");
		me->set("hp",0l);
		message_vision(msg, me);
		me->unconcious();
		return ;
	}

	me->add("hp",-2000);
	me->add("mp",1500);

	snprintf(msg ,255,"һ�󵭰�ɫ�Ĺ�â��$N����������");
	message_vision(msg, me);

	me->call_out(do_kmr, 1, 1, 1);	// Keep Manalock
}

FORCE_END;
