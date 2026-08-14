class AHeroDefaultAS : ANovaCharacter
{
    UPROPERTY(DefaultComponent)
    UInputComponent ScriptInputComponent;

    UPROPERTY(DefaultComponent, Attach = CharacterMesh0, AttachSocket = ik_hand_gun)
    USkeletalMeshComponent WeaponMesh;

    UPROPERTY(DefaultComponent)
    USkeletalMeshComponent Cosmetic;

    UPROPERTY()
    UAnimMontage ReloadAnim;

    UPROPERTY()
    UAnimMontage WeaponReloadAnim;

    default Cosmetic.RelativeLocation = FVector(0.0, 0.0, -90.0);
    default Cosmetic.RelativeRotation = FRotator(0.0, -90.0, 0.0);

    UPROPERTY()
    float Forward;

    UPROPERTY()
    float Right;

    default WeaponMesh.SetCollisionEnabled(ECollisionEnabled::NoCollision);
    default Cosmetic.bUseAttachParentBound = true;

	UFUNCTION(BlueprintOverride)
	void BeginPlay()
	{
        ScriptInputComponent.BindKey(EKeys::R, EInputEvent::IE_Pressed, FInputActionHandlerDynamicSignature(this, n"OnShiftPressed"));

        ScriptInputComponent.BindKey(EKeys::A, EInputEvent::IE_Pressed,FInputActionHandlerDynamicSignature(this, n"OnMovementPressed"));
        ScriptInputComponent.BindKey(EKeys::A, EInputEvent::IE_Released,FInputActionHandlerDynamicSignature(this, n"OnMovementReleased"));

        ScriptInputComponent.BindKey(EKeys::D, EInputEvent::IE_Pressed,FInputActionHandlerDynamicSignature(this, n"OnMovementPressed"));
        ScriptInputComponent.BindKey(EKeys::D, EInputEvent::IE_Released,FInputActionHandlerDynamicSignature(this, n"OnMovementReleased"));

        ScriptInputComponent.BindKey(EKeys::W, EInputEvent::IE_Pressed,FInputActionHandlerDynamicSignature(this, n"OnMovementPressed"));
        ScriptInputComponent.BindKey(EKeys::W, EInputEvent::IE_Released,FInputActionHandlerDynamicSignature(this, n"OnMovementReleased"));

        ScriptInputComponent.BindKey(EKeys::S, EInputEvent::IE_Pressed,FInputActionHandlerDynamicSignature(this, n"OnMovementPressed"));
        ScriptInputComponent.BindKey(EKeys::S, EInputEvent::IE_Released,FInputActionHandlerDynamicSignature(this, n"OnMovementReleased"));

        ScriptInputComponent.BindVectorAxis(EKeys::MouseX, FInputVectorAxisHandlerDynamicSignature(this, n"OnMouseX"));
        ScriptInputComponent.BindVectorAxis(EKeys::MouseY, FInputVectorAxisHandlerDynamicSignature(this, n"OnMouseY"));

        Cosmetic.SetLeaderPoseComponent(Mesh);
	}

    UFUNCTION()
    void OnMouseX(FVector AxisValue)
    {
        AddControllerYawInput(AxisValue.X);
    }

    UFUNCTION()
    void OnMouseY(FVector AxisValue)
    {
        AddControllerPitchInput(AxisValue.X);
    }

    UFUNCTION()
    void OnMovementPressed(FKey Key)
    {
        if (Key == EKeys::D) {
            Right += 1;
        }

        if (Key == EKeys::A) {
            Right += -1;
        }

        if (Key == EKeys::W) {
            Forward += 1;
        }

        if (Key == EKeys::S) {
            Forward += -1;
        }
    }

    UFUNCTION()
    void OnMovementReleased(FKey Key)
    {
        if (Key == EKeys::D) {
            Right -= 1;
        }

        if (Key == EKeys::A) {
            Right -= -1;
        }

        if (Key == EKeys::W) {
            Forward -= 1;
        }

        if (Key == EKeys::S) {
            Forward -= -1;
        }
    }

    UFUNCTION(BlueprintOverride)
    void Tick(float DeltaSeconds)
    {
        AddMovementInput(ActorForwardVector * Forward);
        AddMovementInput(ActorRightVector * Right);
    }

    UFUNCTION()
    void OnShiftPressed(FKey Key)
    {
        if (Mesh != nullptr && Mesh.AnimInstance != nullptr) {
            Mesh.AnimInstance.Montage_Play(ReloadAnim);
        }

        if (WeaponMesh != nullptr && WeaponMesh.AnimInstance != nullptr) {
            WeaponMesh.AnimInstance.Montage_Play(WeaponReloadAnim);
        }
    }

};
