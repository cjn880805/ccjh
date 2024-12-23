//taiji_quan.h ̫��ȭ
//sound��hy2������skill���о�����д�������ˡ�

SKILL_BEGIN(CStaiji_quan);

void create()
{
	set_name("̫��ȭ");
	set("valid_force", "taiji_shengong");

	Magic_t * magic;

	magic = add_magic("zhen", do_zhen);
	magic->name = "���־�";
	magic->mp = 100;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("ji", do_ji);
	magic->name = "���־�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("jielidali", do_jielidali);
	magic->name = "��������";
	magic->mp = 200;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("zhan", do_zhan);
	magic->name = "ճ�־�";
	magic->mp = 500;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("zhenup", do_zhenup);
	magic->name = "�����";
	magic->mp = 1000;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, lvl;
	}action[] = {
		{"$Nʹһ�С���ȸβ����˫�ֻ��˸���Ȧ������$n��$l", 100,50,0,},
		{"$Nʹһ�С����ޡ��������������£���������ӳ�������$n��$l", 120,48,5,},
		{"$N���ֻ��գ������ɹ����ƣ���������ʹһ�С�������ʽ������$n��$l��ȥ", 140,46,10},
		{"$N˫�ֻ������������ϣ��������£�ʹһ�С��׺����᡹���ֻ�$n�����ź�$l", 160,44,15,},
		{"$N��������ǰ���£�����΢ת������һ����Ȧ��ʹһ�С�§ϥ�ֲ���������$n��$l", 100,42,20},
		{"$N�������������������ںϣ�ʹһ�С��ֻ����á�����$n��$l��ȥ", 200,40,25,},
		{"$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ�С���׿�����������$n��$l", 220,38,30,},
		{"$N���ǰ̤�벽������ʹһ�С������롹��ָ������$n��$l��ȥ", 240,36,35,},
		{"$N�С���ͨ�ۡ������һ���������������Ͼ�����Ʋ������$n��$l��ȥ", 260,34,40,},
		{"$N��������ԣ�ת�����������·ֱ�ӳ�������ʹһ�С�б��ʽ��������$n��$l", 280,32,45,},
		{"$N�����鰴������ʹһ�С��������š�����$n��$l��ȥ", 300,30,50,},
		{"$N˫����ȭ����ǰ��󻮻���һ�С�˫����������$n��$l", 320,28,55,},
		{"$N�����黮������һ�ǡ�ָ�ɴ�������$n���ɲ�", 340,26,60,},
		{"$Nʩ��������ʽ�������ֻ���$n��$l�����ֹ���$n���ɲ�", 360,24,65,},
		{"$N�ɱ۴��֣�����ǰ����������ʹһ�С����֡�������$n��$l", 380,22,70,},
		{"$N������������ʹһ�С��𼦶���������$n��$l��ȥ", 400,20,75,},
		{"$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ�С���̽��", 420,18,80,},
		{"$N����ʹһʽ�С���Ů���󡹣�������$n��$l��ȥ", 440,16,85,},
		{"$N���־���ǰ��������ǰƲ����ʹһ�С�����Ʋ��������$n��$l��ȥ", 460,14,90,},
		{"$N�����鰴������ʹһ�С�ת����ȡ�����$n��$l��ȥ", 480,12,95,},
		{"$N�������ϻ�������������ʹһ�С�������������$n��$l��ȥ", 500,10,100,},
		{"$Nʹһ�С��Դ���������§��ϥ���������´���$n��$l", 520,8,110,},
		{"$N˫���ȱ�����״�����طֿ������������£�һ�С�Ұ����ס�����$n��$l�����Ŵ�ȥ", 480,6,120,},
		{"$N��������ǰ���£��ұ�΢����ʹһ�С�������ɽ������$n��$l��ȥ", 500,4,130,},
		{"$N˫�־��¸�����������ǰ����ʮ��״��һʽ��ʮ���֡�����$n��$l��ȥ", 520,2,140,},
		{"$N���̤һ���鲽��˫�ֽ����ʮ��ȭ��һ�С��������ǡ�����$n��$l��ȥ", 540,0,150,},
		{"$N��������ڳ���������ֱ���ұ�΢����ʹһ�С���������$n��$l�����Ŵ�ȥ", 560,-2,160,},
		{"$N˫���쿪������Ϊ�ᣬ����������һ����Բ����һ�С�ת�����������$n�������¶�������������Ӱ֮��", 580,-4,170,},
		{"$N˫����ȭ�����ֻ����������ʣ����ֻ�����ǰ�Ƴ���ȭ�������һ�С��乭�仢����ֱ��$n���Ѷ�ȥ", 600,-6,180,},
		{"$N˫������ǰ���ƣ��ɸ�����ǰ�����Ƴ���һ�С�����Ʊա���һ�ɾ���ֱ��$n", 620,-8,200,},
	};
	
	int level = me->query_skill("taiji_quan", 1);
	for(int i=30; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
}

int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("�������������̫��ȭ��");
	me->receive_damage("hp", 25);
	me->add("mp", -10);
	return 1;
}

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("��̫��ȭ������֡�");
	if (me->query_skill("taiji_shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷���̫��ȭ��");
	return 1;
}
//���ǽ����������֣���ϧsound����д������ˣ���Ҫsoundȱ�ٹ����˺������Ĳ��ִ��룬������޸ġ�
/* ----------------
string perform_action_file(string action)          //sound���ᡣ
{                                                  //
	return __DIR__"taiji-quan/" + action;      //
}                                                  //
*/

char * hit_ob(CChar *me, CChar *victim, LONG & damage)
{
		CContainer * wp1;
        string msg;
        int p,j,skill, mp, mp1;
        
		wp1 = victim->query_weapon();
        skill = me->query_skill("taiji_quan", 1);
        mp = me->query("mp");
        mp1 = victim->query("mp");
        if(me->query_temp("tjj_jie"))
        {
	        if(wp1) 
			{
				msg = "\n$N˫��������̫��������$n��";
				msg += wp1->name();
				msg += "��һ�ƣ�";
			}
        	else msg = "\n$N˫�ֻ������������̫��������";

            if(random(me->query("str"))< victim->query("str")/3)
            {
		        msg +="$n������$N�Ľ������������㷢��������\n";
		        damage=damage*2+100;
		        me->receive_damage("hp",damage);
		        p=me->query("hp")*100/me->query("max_hp");
		        if(damage<100)
		                msg +="���$NӲ��$n��һ�����ƺ�һ����\n";
		        else if(damage<200)
		                msg +="���$NӲ��$n�������𣬡��١���һ������������\n";
		        else if(damage<300)
		                msg+="���$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
                else msg+="���$N��$n������һ����ǰһ�ڣ�����������ߵķ������ɳ�������\n";

		        msg += "( $N";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
		    }
	        else if(mp >= mp1 + damage)
            {
                msg += "$n��������̫��ȭ��������������ȥ��\n",              
                victim->receive_damage("hp", 100 + damage/2 + victim->query("jiali")*2);
                p = victim->query("hp")*100/victim->query("max_hp");
                msg += g_Combatd.damage_msg(damage/2, "����");
                msg += "( $n";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
                j=-8000; 
            }
	        else if(mp >= mp1/2+random(mp1/2)+random(damage))
            {
                msg += "$n��������̫��ȭ��������ж��һ�ԣ�\n";
            }
            else if(mp > mp1/2+damage)
            {
                msg += "$n��������̫��ȭ��������ж����һ���֣�\n"; 
                me->receive_damage("hp",damage/3+random(damage));               
              	p=me->query("hp")*100/me->query("max_hp");
				msg += g_Combatd.damage_msg(damage/2, "����");
                msg += "( $N";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
			}
			else
			{
                msg += "$N��������̫��ȭ��������ж����һС�룡\n"; 
                me->receive_damage("hp",damage/3); 
             	p=me->query("hp")*100/me->query("max_hp");
				msg += g_Combatd.damage_msg(damage/2, "����");
                msg += "( $N";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
			}           
			
			message_vision(msg.c_str(), me, victim);
        }

	return 0;
}

//perform 
static int do_zhen(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

	if(! target ||! me->is_fighting(target) )
		return notify_fail("�����־�ֻ�ܶ�ս���еĶ���ʹ�á�");

	if ( me->query_weapon() )
		return notify_fail("�������ֲ���ʹ�á����־���");		

	if( me->query_skill("taiji_quan", 1) < 30 )
		return notify_fail("���̫��ȭ������죬����ʹ�á����־���");

	if( me->query_skill("taiji_shengong", 1) < 30 )
		return notify_fail("���̫���񹦲����ߣ��������������˵С�");

	if( me->query("mp") < 100 )
		return notify_fail("����������̫��������ʹ�á����־���");

	msg = "\n$NĬ���񹦣�ʹ��̫��ȭ�����־�����ͼ����������$n��\n";
	
	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		int damage = me->query_skill("taiji_shengong", 1);
		damage = damage/2 + random(damage/2);
		damage =damage*(1+me->query_temp("apply/���־�"));
		target->receive_damage("hp", damage);
		target->receive_wound("hp", damage/3);
		me->add("mp", -damage/3);
		
		if( damage < 20 )
			msg += "���$n�ܵ�$N�����������ƺ�һ����";
        else if( damage < 40 )
			msg += "���$n��$N���������𣬡��١���һ������������";
        else if( damage < 80 )
			msg += "���$n��$N������һ���ؿ������ܵ�һ���ش�����������������";
		else
			msg += "���$n��$N������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��";
	}
	else 
	{
		me->start_busy(4);
		msg += "����$p������$P����ͼ����û���ϵ���";
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

// zhen.c ̫��ȭ�������־�
// snowman

//���������޷����
//string *taiji_msg = ({"��ȸβ","����","��������","�׺�����","§ϥ����","��������","��̽��",
//"����ʽ","������","�𼦶���","��Ů����","��������","�乭�仢","������ɽ",});

static int do_ji(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	static char taiji_msg[14][255] = {
		"��ȸβ","����","��������","�׺�����","§ϥ����","��������","��̽��",
			"����ʽ","������","�𼦶���","��Ů����","��������","�乭�仢","������ɽ"};

	if( ob && ob->is_character())
		target = (CChar * )ob;

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭҪּ�����ɷ��ɣ���û�����á�̫�������������ʹ�á������־���");
        if( me->query("mp") < 500 )
                return notify_fail("����������������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�");                   
        if( me->query_temp("weapon") )
                return notify_fail("���ȷ������е�������˵�ɣ���");     

		if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
			return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
     
        msg = "\n$CYN$Nʹһ��̫��ȭ��";
		msg += taiji_msg[random(14)];
		msg += "�����ҽ�ʵ������飬����$RED������$CYN�־���ճ��ճ�棬�����Ѵ�ס$p���ϣ�\n";
        
        //int force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("unarmed")) > target->query_skill("unarmed")/2)
        {
                me->start_busy(2);
                if(!target->is_busy()) target->start_busy(random(2));
                
                int damage = me->query_skill("force");
                if(me->query("mp") > target->query("mp")*2) damage *= 2;
                else if(me->query("mp") > target->query("mp")*3/2) damage += random(damage);
                else if(me->query("mp")*2 < target->query("mp")) damage /= 2;
                else if(me->query("mp") < target->query("mp")) damage -= random(damage);
                else damage = damage/2 + random(damage);
				damage =damage*(1+me->query_temp("apply/���־�"));
                if(damage> 10000) damage = 8000+random(2000); 
                target->receive_damage("hp", damage);
                me->add("mp", -(damage/4));
                msg += "$HIR����$P�ᾢ������$p����ôһ�������ӱ��Լ��ľ������ò���������ǰһ�壬���������$COM";       
        } 
        else
        {
                me->start_busy(3);

                me->add("mp", -150);
                msg += "$HIY$p�����龰��һ�����棬��æ�ջ��Լ��ľ�����������ã�$COM";
        }
        message_vision(msg.c_str(), me, target);
        return 1;
}

static int do_jielidali(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

	if( !me->is_fighting() ) 
		return notify_fail("������������ֻ����ս����ʹ�á�");

	if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

	if( target != me ) 
		return	notify_fail("��ֻ�ܽ������������������Լ������ϡ�");

	if( me->query_weapon())
		return notify_fail("����Ҫ�������е�������");

	if( DIFFERSTR( me->querystr("family/family_name"), "�䵱��"))
         return notify_fail("�㲻���䵱�ɵĵ��ӣ�����ʹ�þ��У�");

	if( me->query_skill("taiji_quan", 1) < 100 )
		return notify_fail("���̫��ȭ������죬����ʹ�á�������������");
	if( me->query_skill("taiji_shengong", 1) < 100 )
		return notify_fail("���̫���񹦲�����죬����ʹ�á�������������");
	if( me->query("int") < 20 )
		return notify_fail("��Ĳ���̫���ˣ������ˡ�������������");
	if( me->query_dex() < 30 )
		return notify_fail("����ٶ�̫�������ʺ�ʹ�á�������������");

	if( me->query("mp") < 200  ) 
		return notify_fail("�������������");

	if( me->query_temp("tjj_jie") ) 
		return notify_fail("���Ѿ����˹����ˡ�");

	int skill = me->query_skill("taiji_quan",1);
	message_vision("$HIR$Nʹ��̫��ȭ���ľ��裬��ס�Լ��������ҪѨ���������ƽ�Է���ʽ��$COM", me);
	me->set_temp("tjj_jie", 1);

	me->call_out(remove_effect, skill/5);

	me->add("mp", -200);
	me->start_busy(3);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
	ob->delete_temp("tjj_jie");
	tell_object(ob, "$HIY��ġ�����������������ϣ���Чʧ���ˡ�$COM");
}

// zhen.c ̫��ȭ��ճ���־�
// snowman
static int do_zhan(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

        if(! target ||! me->is_fighting(target) )
                return notify_fail("��ճ���־�ֻ�ܶ�ս���еĶ���ʹ�á�");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭ��Ҫ���ڽ�չδչ����û�����á�̫�������������ʹ�á�ճ���־���");
        if( me->query("mp") < 500 )
                return notify_fail("����������������ǿ��ʹ�á�ճ���Ƿ��Ӳ������������ģ�");                   
        if ( me->query_weapon() )
                return notify_fail("���ȷ������е�������˵�ɣ���");     
		if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
			return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");

        if( target->is_busy() )
                return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʹ�á�ճ���־���");   
                
        msg = "\n$CYN$Nһ��һʽ�ڽڹᴮ���糤����ӣ�$RED��ճ��$CYN��$n���ϣ�һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ���������಻�ϣ����ϲ�����\n";
        
        if(random(me->query("combat_exp")) > target->query("combat_exp")/2)
		{
                int damage = me->query_skill("taiji_quan", 1)/20; 
                damage = 2+random(damage);
                if(damage > 7) damage = 7; 
                target->start_busy(damage);
                me->add("mp", -(damage*40));
                msg += "$HIR����Ȧ��Ȧ��ʱ���׵�$p����ײײ�������������㲻�ȣ������оƻ��ԣ�$COM";       
        } 
        else
        {
                me->start_busy(3);

                me->add("mp", -150);
                msg += "$HIY$pֻ����$P̫��ȭ����֮�£��޿ɵ�����ֻ��ֻ���˾����㣬ƮȻ������$COM";
        }
        message_vision(msg.c_str(), me, target);
        return 1;
}
// zhen.c ̫��ȭ�����־�
// snowman

//string *taiji_msg = ({"ʮ����","����Ʊ�","������","Ұ�����","б����","����","����","��ͨ��"});
static int do_zhenup(CChar * me, CContainer * ob)
{	
	CChar * target = NULL;
	string msg;

	if( ob && ob->is_character())
		target = (CChar * )ob;

        if(! target ||! me->is_fighting(target) )
                return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�");

//        if(!me->query_temp("taiji"))
//                return notify_fail("̫��ȭ���������ⲻ�ϣ���û�����á�̫�������������ʹ�á����־���");

        if( me->query("mp") < 1000 )
                return notify_fail("����������������ǿ��ʹ�������ֻ���˵����Լ���");

		if(DIFFERSTR(me->querystr("family/family_name"), "�䵱��") && me->querymap_temp("biwu"))
			return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
                   
        if ( me->query_weapon() )
                return notify_fail("�������ֲ���ʹ������У�");;                   
          
//        msg = "$CYNͻȻ��$Nһ�С�"+taiji_msg[random(sizeof(taiji_msg))]+"����˫������������һ��ԲȦ�ѽ�$n��ס��̫��ȭ��"RED"����"CYN"�־��漴ʹ����$COM";
        msg = "\n$CYN$NĬ���񹦣�˫������������һ��ԲȦ�ѽ�$n��ס��̫��ȭ��$RED�����$CYN�漴ʹ����\n";
        
        int force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("force")) > target->query_skill("force")/2)
        {
                if(me->query("mp") < target->query("mp"))
                {
                       me->start_busy(3);
                       if(!target->is_busy()) target->start_busy(3); 
                       me->add("mp", -force/2);
                       target->add("mp", -force/2);
                       msg += "$HIYֻ����ž����һ����$p��$P����������ƴ�������������˼�����\n";
                       message_vision(msg.c_str(), me, target);
                       return 1;
                 }
                me->start_busy(3);
                if(!target->is_busy()) target->start_busy(2+random(3));
                
                int damage = me->query_skill("force")*2;                
                double at = double(me->query("mp")) / double(target->query("mp")+1);
                if(at < 1)
				{
					if(at < 0.5) damage /= 2;
					damage /= 2;
				}
                else damage = int(damage * at);
                if(damage> 20000) damage = 18000+random(2000); 
				target->receive_damage("hp", damage);
				target->receive_wound("hp", damage/4);
                if(target->query("mp") >= damage/4) target->add("mp", -(damage/4));
                else target->set("mp", 0l);

                me->add("mp", -(damage/4));
                if(damage > 1000)
                   msg += "$HIY̫��֮�����಻�ϣ�������ȥ�пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ����������һ�죬$pһ����ͷ���ʶϣ�$COM\n";
				if(damage > 2000)
                   msg += "$HIR$N���������������ʹ��ʱ���಻�ϣ����ſ�����������$pȫ�������ͷҲ��һһ�ʶϣ�$COM\n";
                int p = target->query("hp")*100/target->query("max_hp");
                msg += g_Combatd.damage_msg(damage, "����");
	            msg += "( $n";
				msg += g_Combatd.eff_status_msg(p);
				msg += " )";
        } 
        else
        {
                me->start_busy(3);
                me->add("mp", -300);
                msg += "$HIY$pһ�����ԣ�����һ�󼱹���$P��ʱ��æ���ң���Ҳ���������У�$COM";
        }

        message_vision(msg.c_str(), me, target);
        return 1;
}

SKILL_END;
