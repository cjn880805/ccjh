// lonely_sword.h ���¾Ž�
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSlonely_sword);

virtual void create()
{
	set_name( "���¾Ž�");
	set("valid_force", "zixia_shengong");

	
	Magic_t * magic;

	magic = add_magic("po", do_po);
	magic->name = "�ܾ�ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMMON;

	magic = add_magic("poanqi", do_poanqi);
	magic->name = "�Ƽ�ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pobian", do_pobian);
	magic->name = "�Ʊ�ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("podao", do_podao);
	magic->name = "�Ƶ�ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pojian", do_pojian);
	magic->name = "�ƽ�ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("poqi", do_poqi);
	magic->name = "����ʽ";
	magic->mp = 250;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("poqiang", do_poqiang);
	magic->name = "��ǹʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("posuo", do_posuo);
	magic->name = "����ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("pozhang", do_pozhang);
	magic->name = "����ʽ";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255]=
	{
		"ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�",
		"$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ���������������",
		"$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�������������ͼ��ʹ$P���С�",
		"$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������",
		"$n�������ܣ��ٽ������ʹ�������両�ࡹ����$P��$l���뵲������С�",
		"$nͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ���������$Pһ�ʣ���\nͼͻ��$P�Ĺ��ƣ�"
		"$nͦ��һ�����ǡ����Ƴ�ᶡ��ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣",
		"ֻ��$n���˷���������Ʈ�磬�����һʽ�������������������޶�����׽���ص�ס��$P��\n������",
		"$n���˷�����ʹ����ɽ���С�������롹��ɭɭ�����������ܣ��ܿ���$P������",

	};
	return parry_msg[random(9)];
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n��$l��", 10, 5, 30,0 ,"����",},
		{"$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ���񽣣�", 10, 0, 30,7 ,"����",},
		{"$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼��", 10, 5, 40, 14,"����",},
		{"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ��", 20, 15, 40, 21,"����",},
		{"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ\n���ƻ���$n��$l��", 20, 0, 50, 28,"����",},
		{"ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������̩ɽʮ���̡�\nΪһ������$n��", 30, 10, 55,35 ,"����",},
		{"$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������;��ͻȻת\n�򣬴��$n����֮�⣡", 40, 5, 60, 42,"����",},
		{"$N����������һ�����ǡ�������ɽ��������$w����ն�䣬ֱ����$n��$l��", 50, 0, 80, 49,"����",},
		{"$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��", 60,20 ,70 ,56 ,"����",},
		{"$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n��", 70, 0, 90, 63,"����",},
		{"$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ������\n����$n��", 80, 20, 80, 70,"����",},
		{"$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ�����Ľ���\n��¶���ţ�", 90, 5,90 ,77 ,"����",},
		{"ȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ�У�", 100, 15,60 ,84 ,"����",},
		{"$N�˽���磬��������з���$n��$l�����Ա�$n���أ��������ǡ���ħ����\n�ġ�����ʽ����", 120, 0, 95, 91,"����",},
		{"$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ�������", 140, -10, 120, 98,"����",},
		{"$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ��", 160, 30, 50,105 ,"����",},
		{"$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô������",180 , 5, 80, 112,"����",},
		{"$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻã�", 200, 0, 85,119 ,"����",},
		{"$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò��أ�", 220, -10, 100,126 ,"����",},
		{"$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ���\n�������ƣ�", 240, -15, 120, 133,"����",},
		{"$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ��", 260, 0, 100, 140,"����",},
		{"$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼�飡", 280, 40, 60,147 ,"����",},
		{"$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l��", 300, 20, 120, 154,"����",},
		{"$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡", 400, 50, 165, 180,"����",},

		{"$HIY����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n��$l��", 405, 25, 170,200 ,"����",},
		{"$HIY$N������$n�ӳ�$HIY��Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ���񽣣�", 410, 40, 170,220 ,"����",},
		{"$HIY$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼��", 420, 45, 175, 240,"����",},
		{"$HIY$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ��", 425, 45, 180, 260,"����",},
		{"$HIY$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ\n���ƻ���$n��$l��", 430, 20, 185, 300,"����",},
		{"$HIYȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������̩ɽʮ���̡�\nΪһ������$n��", 435, 25, 190,320 ,"����",},
		{"$HIY$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������;��ͻȻת\n�򣬴��$n����֮�⣡", 440, 35, 195, 340,"����",},
		{"$HIY$N����������һ�����ǡ�������ɽ��������$w����ն�䣬ֱ����$n��$l��", 445, 10, 200, 360,"����",},
		{"$HIY$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ��", 450,20 ,205 ,380 ,"����",},
		{"$HIY$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n��", 455, 40, 210, 400,"����",},
		{"$HIY$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ������\n����$n��", 460, 20, 215, 420,"����",},
		{"$HIY$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ�����Ľ���\n��¶���ţ�", 465, 0,220 ,440 ,"����",},
		{"$HIYȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ�У�", 470, 15,225 ,460 ,"����",},
		{"$HIY$N�˽���磬��������з���$n��$l�����Ա�$n���أ��������ǡ���ħ����\n�ġ�����ʽ����", 475, 0, 230, 500,"����",},
		{"$HIY$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ�������", 480, -10, 235, 520,"����",},
		{"$HIY$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ��", 485, 30, 240,540 ,"����",},
		{"$HIY$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô������",490 , 5, 245, 560,"����",},
		{"$HIY$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻã�", 495, 0, 250,580 ,"����",},
		{"$HIY$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò��أ�", 500, -10, 255,600 ,"����",},
		{"$HIY$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ���\n�������ƣ�", 510, -15, 260, 620,"����",},
		{"$HIY$HIY$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ��", 515, 0, 270, 640,"����",},
		{"$HIY$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼�飡", 520, 40, 275,660 ,"����",},
		{"$HIY$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l��", 525, 20, 280, 680,"����",},
		{"$HIY$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ⣡", 540, -45, 300, 700,"����",},
	};
	int level = 0;
	
	for(int i=48; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lonely_sword", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	CContainer * ob;
	
	if( DIFFERSTR(me->querystr("family/family_name"), "��ɽ��")|| DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("���¾Ž�ֻ�����������ǰ��ѧϰ��");
	if(  me->query("max_mp") < 600 )
		return notify_fail("�������������û�а취�����¾Ž���");
	if(  me->query_skill("zixia_shengong",1)<100)
		return notify_fail("���¾Ž����������ϼ�񹦲�����ϰ��");
	if( !(ob = me->query_weapon())
        ||  DIFFERSTR(ob->querystr("skill_type"), "sword") )
		return notify_fail("���������һ�ѽ�������������");
	if ( me->query_skill("lonely_sword",1) > 120)
		return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("���¾Ž�ֻ��ͨ�����ܾ�ʽ����������");
}

//perform 
static int do_po(CChar * me, CContainer * ob)
{
	LONG jing_cost, exp;
	CContainer * weapon;
	string msg;
	
    int skill = me->query_skill("lonely_sword",1);
    jing_cost =  me->query("int") - 45;
	
	//      if(my_fam["generation"] != 13)
    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�á��ܾ�ʽ����");
	
    if( me->is_fighting() )
		return notify_fail("���ܾ�ʽ��������ս����������");
	
    if (!(weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("�������ȥ��һ�ѽ���");
	
    if( skill < 20)
		return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����");
	
    if( me->query("mp") < 200 )
		return notify_fail("�������������û�������������ܾ�ʽ����");
	
    if( me->query("hp") < -jing_cost )
		return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����");
	
    exp =  me->query_combat_exp();
    if( skill*skill*skill/10 > exp )
		return notify_fail("���ʵս���鲻�����޷���ᡸ�ܾ�ʽ����");
	
	if( skill  >= CChar::level2skill(me->query("level")) )
		return notify_fail("��ĵȼ������������ٶ�Ҳû�á�");
	
    msg = "$Nʹ�����¾Ž�֮���ܾ�ʽ����������$n���������̡�";
    	
    me->add("mp", -50);
    me->add("hp", jing_cost);
	
    if ( skill < 60)
		me->improve_skill("lonely_sword",10);
    else if (skill < 90)
		me->improve_skill("lonely_sword",10+random( me->query("int")- 9));
    else if (skill < 140)
		me->improve_skill("lonely_sword",10+random( me->query("int")*2-9));
    else if (skill < 200)
		me->improve_skill("lonely_sword",10+random( me->query("int")*4-9));
    else
		me->improve_skill("lonely_sword",10+random( me->query("int")*8-9));
	
    msg += "$P�ġ����¾Ž��������ˣ�";
    me->start_busy(random(3));
    message_channel("practice", msg.c_str(), me, weapon);
    return 1;
}

static int do_poanqi(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;
	
    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if( !target || !me->is_fighting(target) )		//bug,has remove lanwood 2001-07-25
        return notify_fail("���Ƽ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (!(weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "throwing"))
		return notify_fail("�Է�û��ʹ���������ò��ˡ��Ƽ�ʽ����");
	
    if( skill < 50)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ƽ�ʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á��Ƽ�ʽ����");
	
    msg = "$N�ٽ����㣬������¾Ž�֮���Ƽ�ʽ��, ��$n��������";
	msg += weapon2->name();
	msg += "�����$n������ȥ��\n";

    int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("throwing", 1);
    if( dp < 1 )
		dp = 1;

	if( random(ap) > dp )
	{
		me->add("mp",-50);
		msg += "$n��ʱ��������ǵص�";
		msg += weapon2->name();
		msg += "�������Լ�Ϯ����ȫ���������̱���ø�������Ƶ�";
		
		me->start_busy(random(2));
		target->receive_damage("hp", damage);
		target->start_busy(2);
    }
    else
    {
		me->add("mp",-30);
		msg += "����$n������$N����ͼ�����̽�����";
		msg += weapon2->name();
		msg += "��÷��겻͸�������������ľ��������ڵء�";
		me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_pobian(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if(! target || !me->is_fighting(target) )
        return notify_fail("���Ʊ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if (! (weapon2 = target->query_weapon())
		|| (DIFFERSTR(weapon2->querystr("skill_type"), "dagger")
				&& DIFFERSTR(weapon2->querystr("skill_type"), "hammer")) )
        return notify_fail("�Է�û��ʹ�ֱޡ����������ò��ˡ��Ʊ�ʽ����");
	
    if( skill < 50)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ʊ�ʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á��Ʊ�ʽ����");
	
    msg ="$N��ʹ���¾Ž����Ʊ�ʽ���ƽ�$n���ὣ�ó����ؽ�Ӱ������˿����$n��ȥ��\n";
		
    int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("hammer") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp)
	{
		me->add("mp",-50);
		msg +="$n��ʱ����ѹ������������һ�飬����";
		msg += weapon2->name();
		msg += "���ֶ�����\n" ;
		
		me->start_busy(random(2));
		target->receive_damage("hp", damage);
		target->start_busy(2);
		weapon2->move(me->environment());
		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg +="�ǿ���$n������һ$n��һ�콫���������" ;
		}
	}
	else
	{
		me->add("mp",-30);
		msg +="����$n������$N�Ľ�·�����̲�ȡ���ƣ�ʹ$N���Ʊ�ʽû����ʲô����";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	
	return 1;
}

static int do_podao(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if( ! target || ! me->is_fighting(target))
        return notify_fail("���Ƶ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "blade"))
        return notify_fail("�Է�û��ʹ�������ò��ˡ��Ƶ�ʽ����");
	
    if( skill < 50)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ƶ�ʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á��Ƶ�ʽ����");
	
    msg ="$N��ʹ���¾Ž����Ƶ�ʽ���ƽ�$n���ὣ�ó����ؽ�Ӱ������˿����$n��ȥ��\n";
		
    int damage = 10 + random(skill / 2);
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("blade") / 2;
    if( dp < 1 )
        dp = 1;
	dp = 1;
    if( random(ap) > dp)
    {
    	me->add("mp",-50);
        msg +=  "$n��ʱ����ѹ������������һ�飬����";
        msg += weapon2->name();
        msg +="���ֶ�����\n";
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
        if (weapon2->query("ownmake")==1)
        {
            weapon2->move(target);
            msg += "�ǿ���$n������һ$n��һ�콫���������";
        }
    }
    else
    {
        me->add("mp",-30);
        msg += "����$n������$N�Ľ�·�����̲�ȡ���ƣ�ʹ$N���Ƶ�ʽû�������á�";
        me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_pojian(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if(! target || !me->is_fighting(target))
        return notify_fail("���ƽ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "sword"))
        return notify_fail("�Է�û��ʹ�������ò��ˡ��ƽ�ʽ����");
	
    if( skill < 50)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��ƽ�ʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á��ƽ�ʽ����");

    msg = "$N�ٽ�������ĬǱ���¾Ž�֮���ƽ�ʽ��, ���ལ�⣬�����̵�Ϯ��$n��";
		
	if(weapon2->query("no_duo") && !random(3))
	{
		me->add("mp",-30);
		msg += "����$n������$N�Ľ�·�����̽�����";
		msg += weapon2->name();
		msg += "��÷��겻͸��ʹ$N�ġ��ƽ�ʽ��û�������á�";
		me->start_busy(4);
	}
	else
	{
		int damage = 10 + random(skill / 2);
		int ap = me->query_skill("sword") + skill;
		int dp = target->query_skill("sword") / 2;
		if( dp < 1 )
			dp = 1;
		
		if( random(ap) > dp )
		{
			me->add("mp",-50);
			msg += "$n��ʱ������ǰһ��������һ�飬����";
			msg += weapon2->name();
			msg += "���ֶ�����\n";
			me->start_busy(random(2));
			target->receive_damage("hp", damage);
			if(weapon2->query("no_duo") )
			{
				char msg1[40];
				target->command(snprintf(msg1, 40, "unwield %ld", weapon2->object_id()));
			}
			else
			{
				target->start_busy(2);
				weapon2->move(me->environment());
				if (weapon2->query("ownmake")==1)
				{
					weapon2->move(target);
					msg += "�ǿ���$n������һ$n��һ�콫���������" ;
				}
			}
		}
		else
		{
			me->add("mp",-30);
			msg += "����$n������$N�Ľ�·�����̽�����";
			msg += weapon2->name();
			msg += "��÷��겻͸��ʹ$N�ġ��ƽ�ʽ��û�������á�";
			me->start_busy(4);
		}
	}
    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_poqi(CChar * me, CContainer * ob)
{
	CContainer * weapon;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    int  neili_wound, qi_wound;
	
    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if(! target || ! me->is_fighting(target))
        return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if( skill < 90)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����");
	
    if( me->query("mp") < 250 )
        return notify_fail("��������������޷����á�����ʽ����");
	
    msg = "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ��$n�ĵ��\n";
		
    int ap = me->query_skill("sword") + skill;
    int dp = target->query_skill("force") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        me->add("mp",-150);
        msg += "$N��������ʽ��������б���Է�С����$n��ʱ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������" ;
        neili_wound = 300 + random(skill);
        if(neili_wound > target->query("mp"))
			neili_wound = target->query("mp");
        qi_wound =  me->query_skill("lonely_sword",1)+ me->query_skill("sword",1)/2;
        qi_wound = qi_wound/2 + random(qi_wound);
        if(qi_wound > target->query("hp"))
			qi_wound = 100;
		
        target->add("mp", -neili_wound);
        target->receive_damage("hp", qi_wound);
        target->receive_wound("hp", qi_wound/2);
        target->start_busy(2);
        me->start_busy(random(2));
    }
    else
    {
        me->add("mp",-100);
        msg += "����$n������$N����ͼ�������ؽ��Ż��������������ڻ��е�����";
		me->start_busy(random(3));
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_poqiang(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if(! target || ! me->is_fighting(target))
        return notify_fail("����ǹʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if (! (weapon2 = target->query_weapon())
		|| ( DIFFERSTR(weapon2->querystr("skill_type"), "staff")
		&&  DIFFERSTR(weapon2->querystr("skill_type"), "club") ))
        return notify_fail("�Է�û��ʹǹ�������ò��ˡ���ǹʽ����");
	
    if( skill < 50)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á���ǹʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á���ǹʽ����");
	
    msg = "$Nһʽ���¾Ž�����ǹʽ�����������ɵ�˳�����䣬����$n����ָ��\n";
    
    int damage = 10 + random(skill / 2);
    int dp = 0, ap = me->query_skill("sword") + skill;
    if( EQUALSTR(weapon2->querystr("skill_type"), "staff"))
        dp = target->query_skill("staff") / 2;
    else if( DIFFERSTR(weapon2->querystr("skill_type"), "club"))
        dp = target->query_skill("club") / 2;
	
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
    	me->add("mp",-50);
        msg += "$N������ǹʽ��, $n��ʱ�󾪣�Ϊ����ָ������";
        msg += weapon2->name();
        msg += "���ֶ�����";
		
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
    }
    else
    {
        me->add("mp",-30);
        msg +="����$n������$N�Ľ�·������������";
		msg += weapon2->name();
		msg += "��ǰ���̣���ʹ$N�ջع��ƣ�";
        me->start_busy(4);
    }

    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_posuo(CChar * me, CContainer * ob)
{
	CContainer * weapon, * weapon2;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if(! target || ! me->is_fighting(target))
        return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if (! (weapon2 = target->query_weapon())
		||  DIFFERSTR(weapon2->querystr("skill_type"), "whip"))
        return notify_fail("�Է�û��ʹ�������ò��ˡ�����ʽ����");
	
    if( skill < 60)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á�����ʽ����");
	
    msg ="$Nʹ�����¾Ž�֮������ʽ�����������ǣ�Ѹ���ޱȵص���$n������\n";
    	
    int damage = 10 + random(skill / 2);
    int dp, ap = me->query_skill("sword") + skill;
    dp = target->query_skill("whip") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        me->add("mp",-50);
        msg += "���$n��$p���˸����ֲ���������һ�飬����";
        msg += weapon2->name();
        msg += "���ֶ�����\n";
		
        me->start_busy(random(2));
        target->receive_damage("hp", damage);
        target->start_busy(2);
        weapon2->move(me->environment());
        if (weapon2->query("ownmake")==1)
        {
            weapon2->move(target);
            msg += "�ǿ���$n������һ$n��һ�콫���������" ;
        }
    }
    else
    {
        me->add("mp",-30);
        msg +="����$n������$N����ͼ��Ѹ���˿���ʹ$N�ġ�����ʽ��û�������á�";
		me->start_busy(4);
    }
    message_vision(msg.c_str(), me, target);
	
    return 1;
}

static int do_pozhang(CChar * me, CContainer * ob)
{
	CContainer * weapon;
	string msg;
	CChar * target = NULL;
	int skill = me->query_skill("lonely_sword",1);

	if(ob && ob->is_character())
		target = (CChar *)ob;

    if(DIFFERSTR(me->querystr("family/master_id"), "feng qingyang"))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�");
	
    if(! target || ! me->is_fighting(target) )
        return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�");
	
    if (! (weapon = me->query_weapon())
		||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
        return notify_fail("��ʹ�õ��������ԡ�");
	
    if ( target->query_weapon())
        return notify_fail("�Է������������������ò��ˡ�����ʽ����");
	
    if( skill < 70)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����");
	
    if( me->query("mp") < 200 )
        return notify_fail("��������������޷����á�����ʽ����");
	
    msg ="$Nʹ�����¾Ž�֮������ʽ��, �������ڽ��⣬��ͼ����ʹ��.\n";
    	
    int ap = me->query_combat_exp() + skill * 1000;
    int dp = target->query_combat_exp() / 4;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        me->add("mp",-50);
        msg += "$N��������ʽ��, $n��ʱ������ǰһ��������һ������������һ�ؽ���ð�˳�����" ;
			
		int wound =  me->query_skill("sword",1)/2 + skill;
        wound = wound/2 + random(wound);
        if( wound >  target->query("hp"))
            wound =  target->query("hp");
        me->start_busy(random(2));
        target->receive_damage("hp", wound);
        target->receive_wound("hp", wound/2);
        target->start_busy(2);
	}
    else
    {
        me->add("mp",-100);
        msg += "����$n������$N����ͼ��ȫ�����أ�������ס��$N�Ĺ��ơ�";
        me->start_busy(random(3));
	}

    message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;




