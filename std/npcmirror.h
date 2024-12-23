//�����ñ�׼NPC ������ǿ��Ϊ���N���Ĺ��
//lanwood 2001-04-13
#include <cstring>
#include "../server/Skill.h"
#include "../server/Npc.h"

#define MIRROR_BEGIN(npc_name)	class npc_name : public CNnpcmirror	{	public:	npc_name(){};	virtual ~npc_name(){};
#define MIRROR_END		};	

NPC_BEGIN(CNnpcmirror);

void die()
{
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);

	if(me)	reward_killer(me);
	
	message_vision("$N�ҽ�һ������Ϊ�ҽ���", this);
	DESTRUCT_OB(this, "CNnpcmirror::die");
	return;
}

virtual void reward_killer(CChar * me)
{
}

void eat_yao(char * yaopin)
{
	char msg[40];
	CContainer * yao = load_item(yaopin);
	yao->move(this);
	command(snprintf(msg, 40, "use %ld", yao->object_id()));
}

//�ͷž���
char * chat_msg_combat()
{
	if(query("hp") < query("max_hp") / 3)
	{
		if(random(2) == 0)
		{
			if(perform_action("force heal", 0))
				return 0;
		}

		if(random(3) == 0)
		{
			eat_yao("yaopin_1");
			return 0;
		}

		if(random(3) == 0)
		{
			eat_yao("yaopin_2");
			return 0;
		}		
	}

	if(random(5) == 0 && !query("flag"))
		perform_action("force lieyan", 1);

	return 0;
}

//������Ҿ��� diff Ϊǿ�� 1 ~ 20 Ҫ��10�ġ�
void make_mirror(CChar * me, int diff)
{
	int lvl = 10 + me->query("level") * 3;
	if(lvl>350) lvl=350;//�ز�  û��Ҫ�����NPC��Ϊ���ֵĿ���

	//������һЩ��������
	set_skill("taishan_sword", lvl);
	set_skill("dodge", lvl);
	set_skill("xiaoyaoyou", lvl);
	set_skill("parry", lvl);
	set_skill("force", lvl);
	set_skill("magic", lvl);
	set_skill("unarmed", lvl);

	map_skill("sword", "taishan_sword");
	
	//�������״̬
	CMapping * skill_status, * map_status, * prepare_status;
		
	skill_status = me->query_skills();

	CVector v;
	int i;

	skill_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		set_skill(v[i], (* skill_status)[v[i]] * diff / 10);
	}
		
	map_status = me->query_skill_map();
	
	v.clear();

	map_status->keys(v);

	for(i=0; i<v.count(); i++)
	{		
		map_skill(v[i], map_status->querystr(v[i]));
	}
		
	prepare_status = me->query_skill_prepare();

	v.clear();

	prepare_status->keys(v);

	for(i = 0; i<v.count(); i++)
	{
		prepare_skill(v[i], prepare_status->querystr(v[i]));
	}
			
	set("str", me->query("str"));
	set("int", me->query("int"));
	set("con", me->query("con"));
	set("dex", me->query("dex"));
	
	set("max_hp",  me->query("max_hp") * diff / 10);
	set("eff_hp",  query("max_hp"));
	set("hp",      query("max_hp"));
	set("max_mp",	me->query("max_mp") * diff / 10);
	set("mp",   query("max_mp") * 2);

	set("mp_factor",    me->query("mp_factor") * diff / 10);
	set("combat_exp", me->query("combat_exp") * diff / 10);
	set("level",   me->query("level") * diff / 10);

	//��������
	set_temp("apply/str", me->query_temp("apply/str") * diff / 10);
	set_temp("apply/dex", me->query_temp("apply/dex") * diff / 10);
	set_temp("apply/attack", me->query_temp("apply/attack") * diff / 10);
	set_temp("apply/defense", me->query_temp("apply/defense") * diff / 10);
	set_temp("apply/armor", me->query_temp("apply/armor") * diff / 10);
	set_temp("apply/damage", me->query_temp("apply/damage") * diff / 10);
	set_temp("apply/dodge", me->query_temp("apply/dodge") * diff / 10);
	set_temp("apply/parry", me->query_temp("apply/parry") * diff / 10);

	//���ù�������
	set_name(me->querystr_temp("fool/name"));

	//���ù���ķ���
	map_skill("force", "magic");
	
	//��������Ṧ�ȼ���
	int limit = lvl + lvl / 2;
	if(query_skill("dodge") < limit)	//�����ҵļ���ʵ��̫�ã�ֻ�����Լ��ġ�
		map_skill("dodge", "xiaoyaoyou");
	
	//��������мܵȼ���
	if(query_skill("parry") < limit)	
		map_skill("parry", "taishan_sword");		

	CContainer * weapon = make_weapon(this);
	if(weapon)
	{
		weapon->move(this);
		weapon->wield();
	}
}

//ΪmeѰ������ֵ�����
static CContainer * make_weapon(CChar * me)
{
	int level = 0, max_level = 0;
	
	CMapping * skill_status;
	CSkill * sk;
	string base_skill = "unarmed";
	
	skill_status = me->query_skills();

	CVector v;

	skill_status->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * skl = v[i];
		sk = load_skill(skl);
		if(sk->querystr("base_skill")[0]) continue;	//�߼�����
		if(strcmp(sk->type(), "knowledge") == 0) continue;		//֪ʶ
		if(strcmp(skl, "force") == 0) continue;			//�ڹ�����
		if(strcmp(skl, "parry") == 0) continue;			//�мܳ���
		if(strcmp(skl, "dodge") == 0) continue;			//��������

		level = me->query_skill(skl);	//��������
		if(max_level < level)
		{
			max_level = level;
			base_skill = skl;
		}
	}

	if(! max_level) return 0;

	int lvl = 10 + me->query("level") * 3;
	if(max_level < lvl + lvl / 2)	//����̫��
	{
		max_level = lvl + lvl / 2;
		base_skill = "sword";			//ʹ���Դ��Ľ���
	}

	//���ּ��ܳ���
	if(base_skill == "unarmed" || base_skill == "hand" || base_skill == "finger"
		|| base_skill == "leg" || base_skill == "cuff" || base_skill == "claw"
		|| base_skill == "strike") return 0;
	
	CContainer * weapon = NULL;
	//���ݼ��ܸ�һ������
	weapon = load_item("mujian");
	
	weapon->set_name( "ľ��");
	weapon->set("skill_type", base_skill.c_str());			
	weapon->set_weight(100);		
	
	weapon->set("value", 1);
	weapon->set("rigidity",1000);
	weapon->set("material", "steel");
	weapon->set("wield_msg", "$N����һ��$n�������С�");
	weapon->set("unwield_msg", "$N�����е�$n��������");
	weapon->set("apply/damage", 1);
	weapon->set("owner", "monster");
	return weapon;
};	

virtual void catch_ob(CChar * me)
{
}


char * chat_msg()
{
	//����Ƿ�������ˡ�
	if(random(10))
		return 0;

	message_vision("$N���λ��˼��Σ�գ�ۼ����ʧ�ˣ�", this);
	DESTRUCT_OB(this, "monster::chat_msg");
	return 0;
}
NPC_END;

